
#include "lip_token.h"
#include "lip_listlexer.h"
#include "lip_listparser.h"

#include <iostream>

using namespace std;
using namespace lip;

int main(int argc, char **argv)
{
    if (argc != 2) {
        cerr << "Usage: a.out input" << endl;
        return -1;
    }

    string input(argv[1]);
    ListLexer lexer(input); 

#if 0
    Token token = lexer.nextToken();
    while (token.type() != Lexer::EOF_TYPE) {
        cout << token << endl;
        token = lexer.nextToken();
    }
    cout << token << endl;
#endif
    ListParser parser(&lexer);

    parser.list();

    return 0;
}
