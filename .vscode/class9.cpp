#include <bits/stdc++.h>
using namespace std;

/*
 * 静态数据成员
 * 
 * 用关键字static声明，同一个类中的所有对象都共享该变量
 * 必须在类外定义和初始化，用::来指明所属类
 * 静态变量不依赖于对象而存在，无论是否定义该类的对象，这种类型的变量都存在
 * 静态数据的成员实际上是在类外定义的一个变量，它的生存期和整个程序的生存期一样，在定义对象之前，静态数据成员就已经存在
 * 
 * 静态的函数成员
 * 
 * 同样也有static修饰
 * 与静态数据类似，在对象生成之前就已经存在，就是说对象在产生之前，静态函数成员就能访问其它静态成员
 * 类外代码可以使用类名和作用域操作符来调用静态成员函数
 * 静态成员函数只能引用属于该类的静态数据成员或静态成员函数 
 * 
 */

class Budget {
    static float corpBudget;
    float divBudget;
public:
    Budget() {
        divBudget = 0;
    }
    void addBudget(float b) {
        divBudget += b;
        corpBudget += divBudget;
    }
    static void mainOffice(float);
};

void Budget::mainOffice(float moffice) {
    corpBudget += moffice;
}

int main_1() {
    float amount;
    Budget::mainOffice(amount);//引用
}

/*
 * 友元函数
 * 
 * 友元函数不是类中的成员函数，但它和类的成员函数一样，可以访问类中定义的私有成员
 * 友元函数可以是一个外部成函数，也可以是另外一个类的成员的函数成员
 * 将某个函数声明为一个类的友元方式，前面加个friend
 */

class Point{
    int xPos, yPos;
public:
    Point(int xx = 0, int yy = 0) {
        xPos = xx;
        yPos = yy;
    }
     friend double Distance(Point &a, Point &b);
};
//此时可以不加作用域分辨符
double Distance(Point &a, Point &b) {

}

/*
 * 类的成员函数作为另一个类的友元
 * 
 * A类函数的成员函数声明为B类的友元函数，这个成员函数也称为B类的友元函数
 * 友元成员不仅可以访问自己所在类对象中的私有成员和共有成员，还可以访问fried声明语句所在类对象中的私有成员和共有成员，这样能使两个类相互合作完成某一任务
 * 
 */



/*
 * 对象的赋值问题
 *
 * 
 */