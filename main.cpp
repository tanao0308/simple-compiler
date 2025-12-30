
#include "ast/Compiler.h"
#include "ast/program/Program.h"
#include "sc.tab.hpp"
#include <iostream>

using namespace std;

extern FILE *yyin;

int main() {
    yyin = fopen("../parser/input.sc", "r");
    if (!yyin) {
        cout << "无法读取文件" << endl;
        return 1;
    }
    Compiler compiler;
    yy::parser parser(compiler);
    if (parser.parse() != 0) {
        cout << "编译错误" << endl;
        return 1;
    }
    compiler.print();

    return 0;
}
