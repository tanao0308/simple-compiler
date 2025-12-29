# 一个 flex&bison 的玩具编译器
## 语法示例
```
表达式：
1*2+3/4;
变量定义：
var0 = 1/4;
变量赋值：
var1=1/var0;
函数定义：
def func0 (x)= x/2+x*x;
函数调用
3+func0(10);
```
## 编译命令
``` shell
# 构建项目
mkdir build
cd build
cmake ..
make
# 运行编译器（代码文件为parser/input.sc）
./sc
```