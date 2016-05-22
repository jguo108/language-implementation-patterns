#ifndef LIP_PARSER
#define LIP_PARSER

#include "lip_token.h"

#include "lip_lexer.h"

#include <sstream>

namespace lip
{

class Parser
{
  private:
    Lexer *d_lexer;

    Token  d_lookahead;

  protected:
    void match(int type);

    void consume();

    Token lookahead() const;

  public:
    explicit Parser(Lexer *lexer);
};

// =============================================================================
//                             INLINE FUNCTIONS
// =============================================================================

inline
Parser::Parser(Lexer *lexer)
: d_lexer(lexer)
{
    d_lookahead = lexer->nextToken();
}

inline
void Parser::match(int type)
{
    if (d_lookahead.type() == type) {
        consume();
    } else {
        std::ostringstream oss;
        oss << "Expecting '" << type
            << "', found '" << d_lookahead.type() << "'";
        throw std::runtime_error(oss.str());
    }
}

inline
void Parser::consume()
{
    d_lookahead = d_lexer->nextToken();
}

inline
Token Parser::lookahead() const
{
    return d_lookahead;
}

}

#endif
