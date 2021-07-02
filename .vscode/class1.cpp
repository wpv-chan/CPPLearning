#include <bits/stdc++.h>
using namespace std;
//函数必须是先定义后使用
//若要在后面使用，那要先做原型声明
//原型声明的两种形式
int function1(int ,int);
int function2(int &, int &);
int function3(int a, int b);

//参数的传递可以有两种：传值，传引用
//传值：形参变实参不变(没有&符号)
//传引用, 形参变实参也跟着变
void swap(int &x, int &y);
int main_fun1() {
    int a = 10, b = 20;
    swap(a, b);
    cout<<a<<b<<endl;
}

//若函数的返回类型不是void那么记得写上return语句
//返回单值可以用return，返回多个变量就引用

//变量的内存分配情况
//自由存储的堆区
//栈区(存储局部变量)
//全局数据区
//代码区

//局部变量
//  C++已经自动做好该类变量的内存的释放工作，故可不加auto
//  若未显式赋值或初始化，那么其初值会不确定（全局变量的初值则默认是0）
//全局变量
//  若某个函数修改了全局变量，那么其它函数都“可见”修改后的结果

//局部变量和全局变量同名的时候，局部变量定义优先，若要访问全局变量就要添加作用域运算符::
int a;
void function4() {
    a = 200;
}
int main_fun2() {
    int a = 10;
    function4();
    cout<<a<<::a<<endl;
    return 0;
}

//储存类别修饰符
//auto和register修饰自动存储的变量
//static修饰静态储存(初始化以后就不会改变了)
//extern修饰外部储存(拓展作用域，甚至还可以将函数的作用域扩展到其他文件)

//默认参数也叫缺省参数
//缺省值的设定是在函数原型中给出
void showArea(float length = 20.0, float width = 10.0);

//设置默认值要注意，默认值要集中在函数右边
int function5(int a, int b = 1, int c = 4);

//频繁的函数调用会降低效率，此时要引入内联函数，要在函数前添加inline修饰符
//内联函数是否定义成功取决于编译器
//内联函数不允许出现循环，switch语句以及复杂嵌套的if语句

//函数的重载(同一个函数想实现不同的功能)
//不能使用函数的返回值来区别函数，参数的个数和类型才是区别的地方
int square(int num);
double square(double num1, double num2);


//模板分为函数模板和类模板
//函数模板
template <class T, class T1>
T square(T number) {
    return number * number;
}
int main_fun3() {
    int userInt;
    float userFloat;
    square(userInt);
    square(userFloat);
}
//对应的重载函数
int square(int number) {
    return number * number;
}
double square(double number) {
    return number * number;
}

