#include <bits/stdc++.h>
using namespace std;

/*
 * ###异常处理###
 * 异常是在程序执行期间的突发性事件
 * 异常与错误不同，错误可以通过编译器处理
**/

//1. 抛出异常

float divide(int number, int div) {
    if(div == 0) {
        throw "ERROR: divided by zero. \n";
    }
    else {
        return number/div;   
    }
}

//2. 处理异常

int main() {
    try {
        //可能出现异常的代码
    }
    catch(exception param1) {
        //处理异常1的代码
    }
    catch(exception param2) {
        //处理异常2的代码
    }
    //继续执行的代码
    return 0;
}

