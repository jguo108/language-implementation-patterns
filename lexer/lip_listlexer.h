#ifndef LIP_LISTLEXER
#define LIP_LISTLEXER

#include "lip_lexer.h"

#include "lip_token.h"

namespace lip
{

class ListLexer : public Lexer
{
  public:
    static const int NAME   = 2;
    static const int COMMA  = 3;
    static const int LBRACK = 4;
    static const int RBRACK = 5;

  private:
    void skipWhitespaces();

    bool isLetter(char c) const;

    Token name();

  public:
    explicit ListLexer(const std::string& input);

    virtual Token nextToken();
};

// =============================================================================
//                             INLINE FUNCTIONS
// =============================================================================

inline
ListLexer::ListLexer(const std::string& input)
: Lexer(input)
{
}

inline
Token ListLexer::nextToken()
{
    while (currentChar() != static_cast<char>EOF) {
        switch (currentChar()) {
            case ' ' :
            case '\t':
            case '\n':
            case '\r': {
              skipWhitespaces();
            } break;
            case ',': {
              consume();
              return Token(COMMA, ",");
            } break;
            case '[': {
              consume();
              return Token(LBRACK, "[");
            } break;
            case ']': {
              consume();
              return Token(RBRACK, "]");
            } break;
            default: {
              if (isLetter(currentChar())) {
                  return name();
              }
              std::ostringstream oss;
              oss << "Invalid character: '" << currentChar() << "'";
              throw std::runtime_error(oss.str());
            } break;
        }
    }
    return Token(EOF_TYPE, "<EOF>");
}

inline
bool ListLexer::isLetter(char c) const
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline
Token ListLexer::name()
{
    std::ostringstream oss;

    do {
        oss << currentChar();
        consume();
    } while (isLetter(currentChar()));

    return Token(NAME, oss.str());
}

inline
void ListLexer::skipWhitespaces()
{
    while (currentChar() == ' '
            || currentChar() == '\t'
            || currentChar() == '\n'
            || currentChar() == '\r') {
        consume();
    }
}

}

#endif
