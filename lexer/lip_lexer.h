#ifndef LIP_LEXER
#define LIP_LEXER

#include "lip_token.h"

#include <iostream>

#include <sstream>


namespace lip
{

class Lexer
{
  public:
    static const int EOF_TYPE = 1;

  private:
    std::string d_input;

    size_t      d_curCharIndex;

    char        d_curChar;

  private:
    void match(char c);

  protected:
    void consume();

  public:
    explicit Lexer(const std::string& input);

    char currentChar() const;

    virtual Token nextToken() = 0;
};

// =============================================================================
//                             INLINE FUNCTIONS
// =============================================================================

inline
Lexer::Lexer(const std::string& input)
: d_input(input)
, d_curCharIndex(0)
, d_curChar(input[0])
{
}

inline
char Lexer::currentChar() const
{
    return d_curChar;
}

inline
void Lexer::consume()
{
    ++d_curCharIndex;
    if (d_curCharIndex >= d_input.length()) {
        d_curChar = static_cast<char>(EOF);
    } else {
        d_curChar = d_input[d_curCharIndex];
    }
}

inline
void Lexer::match(char c)
{
    if (d_curChar == c) {
        consume();
    } else {
        std::ostringstream oss;
        oss << "Expecting '" << c << "', found '" << d_curChar << "'"; 
        throw std::runtime_error(oss.str());
    }
}

}

#endif
