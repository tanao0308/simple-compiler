## bison -d ./sc.ypp
生成了一堆文件
### sc.tab.cpp
语法分析器的完整实现代码，Parser 类
### sc.tab.hpp
Token（词法单元）定义和函数声明
### location.hh  position.hh stack.hh
location.hh 跟踪语法元素在源文件中的位置
position.hh 表示具体的行列位置
stack.hh Bison 内部使用的栈实现模板
要使用时，在 sc.l 里包含就行

## flex -o lex.yy.cpp sc.l
生成了 lex.yy.cpp 文件，其实是C文件但为了后续结合C++，强制修改为cpp

