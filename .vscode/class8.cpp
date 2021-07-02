#include <bits/stdc++.h>
using namespace std;

/*
 * 过程化程序的设计缺陷
 *    大量的全局变量
 *    程序复杂
 *    程序难以进行扩充和修改
 *    过程化设计是以过程为中心（函数
 *    OOP以对象为中心，数据和对数据的操作封装在一起
 *    OOP是以对象为中心
 *
 * 类的基本概念
 * class 类名 {
 *     变量名和函数声明
 *     blablabla
 * }
 * */
class Rectangle {
private:
    float width;
    float length;
    float area;

public:
    void setData(float, float);
    void calcArea();
    float getWidth();
    float getLength();
    float getArea();
};

/*
 * 定义成员函数
 * <返回值类型><类名>::<函数名> (参数列表) {
 *     ...
 * }
 *
 * */

void Rectangle::setData(float w, float l) {
    width = w;
    length = l;
}
float Rectangle::getWidth() {
    return width;
}

//定义对象为类的实例化
Rectangle box;
box.setData(10.0, 12.5);
cout<<box.setWidth();
Rectangle *boxPtr;
boxPtr = &box;
boxPtr -> setData(15, 12);

/*
 * 类的多文件组织方式
 *    类的定义储存在头文件里面（类定义文件
 *    成员函数定义储存在.cpp文件（类的实现文件
 *    应用程序通过#include饱含头文件，将类的实现文件和主程序进行联编，从而生成一个完整的程序
 *
 * 私有函数成员的作用
 *    专门用于内部处理的函数，它们在类的外部不能使用，这些函数是私有的
 *    私有函数可以被同一个类中的其它很熟调用
 * */

//内联函数的两种定义方式
//1
class Rectangle1 {
    float width, length, area;
public:
    void setData(float, float);
    void calArea() {
        area = width * length;
    }
};
//2
inline void Rectangle1::setData(float w, float l) {
    width = w;
    length = l;
}

/*
 * 构造很熟和析构函数
 *    构造函数是一个函数成员，在对象创建时，采用给定的值，自动调用该函数将对象中的数据成员初始化
 *    析构函数也是一个函数成员，当对象终止时，将自动调用该函数进行“善后”处理
 *
 * 构造函数的特点
 *    构造函数是与类同名的函数成员
 *    没有返回值，没有void
 *    如果构造函数没有参数，就称之为缺省构造函数
 *    如果程序中未声明，则系统会自动生成一个缺省形式的构造函数
 *    构造函数允许为内联函数，重载函数， 带缺省值的函数
 *
 * */

class InvoiceItem {
    char *desc;

public:
    InvoiceItem() {
        desc = new char[50];
    }
};

int main_1() {
    InvoiceItem stock;//定义的时候自动调用
}

/*
 * 析构函数的特点
 *    析构函数也与类同名
 *    析构函数也没有返回值
 *    析构函数无参数
 *    一个类只能有一个析构函数
 *    若用指针对象来实例化类的时候则需要手动在主函数中添加delete xxx
 * */

class InvoiceItem1 {
    char *desc;
public:
    ~InvoiceItem1() {
        delete []desc;
    }
};


