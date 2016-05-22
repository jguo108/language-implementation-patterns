#ifndef LIP_LISTPARSER
#define LIP_LISTPARSER

#include "lip_parser.h"

#include "lip_listlexer.h"

namespace lip
{

class ListParser : public Parser
{
  private:
    void element();

    void elements();

  public:
    ListParser(Lexer *lexer);

    void list();
};

// =============================================================================
//                             INLINE FUNCTIONS
// =============================================================================

inline
ListParser::ListParser(Lexer *lexer)
: Parser(lexer)
{
}

inline
void ListParser::element()
{
    if (lookahead().type() == ListLexer::NAME) {
        match(ListLexer::NAME);
    } else if (lookahead().type() == ListLexer::LBRACK) {
        list();
    } else {
        std::ostringstream oss;
        oss << "Expecting name or list, found " << lookahead().text();
        throw std::runtime_error(oss.str());
    }
}

inline
void ListParser::elements()
{
    element();
    while (lookahead().type() == ListLexer::COMMA) {
        match(ListLexer::COMMA);
        element();
    }
}

inline
void ListParser::list()
{
    match(ListLexer::LBRACK);
    elements();
    match(ListLexer::RBRACK);
}

}

#endif
