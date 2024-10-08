#ifdef _WIN32
extern "C" __cdecl int SetConsoleOutputCP(unsigned int code_page);
#endif
#include "repl_backend__default.h"
namespace Jakt {
namespace repl_backend__default {
ByteString Jakt::repl_backend__default::Editor::debug_description() const { auto builder = ByteStringBuilder::create();builder.append("Editor("sv);{
JaktInternal::PrettyPrint::ScopedLevelIncrease increase_indent {};
JaktInternal::PrettyPrint::must_output_indentation(builder);
builder.appendff("standard_input_file: {}, ", standard_input_file);
JaktInternal::PrettyPrint::must_output_indentation(builder);
builder.appendff("line_pointer: {}, ", line_pointer);
JaktInternal::PrettyPrint::must_output_indentation(builder);
builder.appendff("prompt: \"{}\"", prompt);
}
builder.append(")"sv);return builder.to_string(); }
ErrorOr<Jakt::repl_backend__default::Editor> Jakt::repl_backend__default::Editor::create(ByteString const prompt,Function<ErrorOr<void>(Jakt::repl_backend__default::Editor&)> const& syntax_highlight_handler) {
{
FILE* std_in = fopen(ByteString::from_utf8_without_validation("/dev/stdin"sv).characters(),ByteString::from_utf8_without_validation("r"sv).characters());
if (std_in == Jakt::jakt__platform__utility::null<FILE*>()){
warnln(StringView::from_string_literal("Could not open /dev/stdin for reading"sv));
return Error::from_errno(static_cast<i32>(42));
}
Jakt::repl_backend__default::Editor const editor = Jakt::repl_backend__default::Editor(std_in,Jakt::jakt__platform__utility::allocate<char>(static_cast<size_t>(4096ULL)),prompt);
return editor;
}
}

ErrorOr<Jakt::repl_backend__common::LineResult> Jakt::repl_backend__default::Editor::get_line(JaktInternal::Optional<ByteString> const prompt) {
{
warn(StringView::from_string_literal("{}"sv),prompt.value_or_lazy_evaluated([&] { return this->prompt; }));
ByteStringBuilder builder = ByteStringBuilder::create();
{
char* const c_string = fgets(this->line_pointer,static_cast<size_t>(4096ULL),this->standard_input_file);
if (c_string == Jakt::jakt__platform__utility::null<char*>()){
return Jakt::repl_backend__common::LineResult::Eof();
}
builder.append_c_string(c_string);
}

return Jakt::repl_backend__common::LineResult::Line(builder.to_string());
}
}

ErrorOr<ByteString> Jakt::repl_backend__default::Editor::get_active_buffer() {
{
return Error::__jakt_from_string_literal(StringView::from_string_literal("Active buffer not supported"sv));
}
}

ErrorOr<void> Jakt::repl_backend__default::Editor::highlight(Jakt::utility::Span const span,Jakt::repl_backend__common::Style const style) {
{
return Error::__jakt_from_string_literal(StringView::from_string_literal("Highlighting not supported"sv));
}
return {};
}

void Jakt::repl_backend__default::Editor::destroy() {
{
fclose(this->standard_input_file);
{
free(line_pointer);
}

}
}

Jakt::repl_backend__default::Editor::Editor(FILE* a_standard_input_file, char* a_line_pointer, ByteString a_prompt): standard_input_file(move(a_standard_input_file)), line_pointer(move(a_line_pointer)), prompt(move(a_prompt)){}

}
} // namespace Jakt
