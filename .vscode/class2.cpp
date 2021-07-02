#include <bits/stdc++.h>
using namespace std;

//函数的递归调用
//  一个函数直接或者间接地调用自己
//使用时必须注意要添加终止条件
int fac(int n) {
    int y;
     
     if(0 == n || n == 1) {
         y = 1;
     }
     else {
         y = n * fac(n - 1);
     }
     return y;
}

//汉诺塔
//同样是个递归算法
int hanoi(int n, char pillar_A, int pillar_B, int pillar_C) {
    if(n == 1) {
        move(pillar_A, pillar_C);
    }
    else {
        hanoi(n-1, pillar_A, pillar_C, pillar_B);
        move(pillar_A, pillar_C);
        hanoi(n-1, pillar_B, pillar_A, pillar_C);
    }
}

void move(char pillar_before, char pillar_after) {
    cout<<pillar_before<<"->"<<pillar_after<<endl;
}
//若有n个盘子，则需要移动2^n-1次

//注意，计算机中循环地效率要比递归要高，如非必要情况建议使用循环进行问题解决

//编译的预处理
//预处理的命令行
//  以“#”开头（宏定义，文件包含，条件编译）

//宏定义
//1.不带参数的
#define NAME //+字符串
//2. 带参数的宏定义
#define MUL(x, y) (x)*(y)//x, y带括号是防止函数中x或者y是一个具体的函数，则会导致优先级的问题
//此时函数中若有MUL(4, 5)则会展开成4*5
//宏定义写在多行上面的时候，要记得在末尾添加续行符“\”

//宏与函数的区别
//1. 宏代换是在编译前进行的
//2. 使用带参数的宏只是简单的字符替换
//3. 宏不存在类型问题

//文件包含
//如果是自己写的文件，那么必须要用“”，系统存在的头文件则还可以使用<>

//条件编译
//自行上网了解宏定义内的循环***
//这样运用条件编译能够大量节省时间

//