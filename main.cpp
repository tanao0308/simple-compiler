#include <iostream>
#include "ast/program/Program.h"
#include "sc.tab.hpp"

using namespace std;

extern FILE* yyin;

int main()
{
    yyin = fopen("../parser/input.sc", "r");
    if (!yyin) {
        cout << "无法读取文件" << endl;
        return 1;
    }
    Program* program = nullptr;
	yy::parser parser(&program);
    if (parser.parse() != 0) {
        cout << "编译错误" << endl;
        return 1;
    }
    if (!program) {
        cout << "no program" << endl;
        return 1;
    }
    program->print();

    return 0;
}
