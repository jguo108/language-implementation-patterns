#ifndef LIP_TOKEN
#define LIP_TOKEN

#include <string>
#include <iostream>

namespace lip
{

class Token
{
  private:
    int         d_type;

    std::string d_text;

  public:
    Token();

    Token(int type, const std::string& text);

    int type() const;

    std::string text() const;
};

// =============================================================================
//                             INLINE FUNCTIONS
// =============================================================================

inline
Token::Token()
: d_type(-1)
, d_text()
{
}

inline
Token::Token(int type, const std::string& text)
: d_type(type)
, d_text(text)
{
}

inline
int Token::type() const
{
    return d_type;
}

inline
std::string Token::text() const
{
    return d_text;
}

inline
std::ostream& operator<<(std::ostream& os, const Token& token)
{
    os << "<" << token.text() << ", " << token.type() << ">";

    return os;
}

}

#endif
