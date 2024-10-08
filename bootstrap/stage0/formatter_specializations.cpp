#include "formatter.h"
namespace Jakt {
namespace formatter {

/* specialisation 0 of function collapse: ["Jakt::lexer::Token"] */
template<> JaktInternal::Optional<Jakt::lexer::Token> collapse<Jakt::lexer::Token>(JaktInternal::Optional<JaktInternal::Optional<Jakt::lexer::Token>> const x);
template<>
JaktInternal::Optional<Jakt::lexer::Token> collapse<Jakt::lexer::Token>(JaktInternal::Optional<JaktInternal::Optional<Jakt::lexer::Token>> const x) {
{
return ({
    auto&& _jakt_value = ([&]() -> JaktInternal::ExplicitValueOrControlFlow<JaktInternal::Optional<Jakt::lexer::Token>,JaktInternal::Optional<Jakt::lexer::Token>> {
auto __jakt_enum_value = (x.has_value());
if (__jakt_enum_value) {return JaktInternal::ExplicitValue(x.value());
}else if (!__jakt_enum_value) {return JaktInternal::ExplicitValue(JaktInternal::OptionalNone());
}VERIFY_NOT_REACHED();
}());
    if (_jakt_value.is_return())
        return _jakt_value.release_return();
    _jakt_value.release_value();
});
}
}
}
} // namespace Jakt
