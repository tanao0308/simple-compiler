%option noyywrap nodefault yylineno noinput nounput

%{
#include "sc.tab.hpp" // 获取 TOKEN 的定义
#define YY_DECL int yylex(yy::parser::semantic_type *yylval, \
		yy::parser::location_type *yylloc)
#define YY_USER_ACTION yylloc->columns (yyleng);
%}

%%
"def"           { return yy::parser::token::DEF; } // 函数定义关键字
[0-9]+          { // 数字
                    yylval->emplace<int>(atoi(yytext)); // 使用 variant 时要用 ->emplace<int>() 模式
                    return yy::parser::token::NUMBER;
                }
[a-zA-Z_][a-zA-Z0-9_]* { // 变量/函数名
                    yylval->emplace<std::string>(yytext);
                    return yy::parser::token::IDENT;
                }
[()+\-*/=;]     { return yytext[0]; } // 单个符号
[ \t\r\n]+      ;   // 忽略空白
.               ;   // 忽略其他字符
%%

