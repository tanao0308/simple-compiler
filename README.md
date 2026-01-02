# 一个 flex&bison 的玩具编译器
## 语法
### 表达式
    支持 + - * / ^ 五种运算
### 变量定义/赋值
    var = 1;
    暂不支持变量与函数参数变量重复
### 条件语句
    if (x) {
        return 7;
    } else {
        return 9;
    }
### 循环语句
    while (x) {
        res = res + x;
        x = x - 1;
    }
### 函数定义/调用
    def func(x)
        return x*x;
    def func(x) {
        a = x^2;
        return a-3;
    }
    func(10);
### 结果输出
    result = 1 + var + func(2);
## 构建项目
``` shell
mkdir build
cd build
cmake ..
make
# 运行编译器（代码文件为parser/input.sc）
./sc
```