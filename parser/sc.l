%option noyywrap nodefault yylineno noinput nounput

%{
#include <stdlib.h>
#include "sc.tab.hpp" // 获取 TOKEN 的定义
#define YY_DECL int yylex(yy::parser::semantic_type *yylval, \
		yy::parser::location_type *yylloc)
#define YY_USER_ACTION yylloc->columns (yyleng);
%}

%%
"def"           { return yy::parser::token::DEF; }
"return"           { return yy::parser::token::RETURN; }
"if"            { return yy::parser::token::IF; }
"else"          { return yy::parser::token::ELSE; }
"while"          { return yy::parser::token::WHILE; }
[0-9]+(\.[0-9]*)?([eE][+-]?[0-9]+)? { // 数字
                char *endptr;
                errno = 0;
                double value = strtod(yytext, &endptr);
                if (errno == ERANGE) {
                    printf("数字超出范围: %s\n", yytext);
                } else if (*endptr != '\0') {
                    printf("转换不完全: %s\n", yytext);
                } else {  // 使用 variant 时要用 ->emplace<int>() 模式
                    yylval->emplace<double>(value);
                }
                return yy::parser::token::NUMBER;
}
[a-zA-Z_][a-zA-Z0-9_]* { // 变量/函数名
                    yylval->emplace<std::string>(yytext);
                    return yy::parser::token::IDENT;
                }
[(){}+\-*/^=;]     { return yytext[0]; } // 单个符号
[ \t\r\n]+      ;   // 忽略空白
.               ;   // 忽略其他字符
%%

