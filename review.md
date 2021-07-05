# C++ 期末复习教案 20210701

## 目录

* 1 [字符串与指针](#1)
   
  * 1.1 [处理字符与字符串](#11-处理字符与字符串)

  * 1.2 [标准C++的String类](#12-标准c的string类)
  * 1.3 [指针的概念、指针变量的定义和使用](#13-指针的概念指针变量的定义和使用)
  * 1.4 [指针与数组](#14-指针与数组)

* 2 [指针与函数](#2)
  
    * 2.1 [参数的传递方式](#21-参数的传递方式)

    * 2.2 [返回指针的函数及指向函数的指针](#22-返回指针的函数及指向函数的指针)
    * 2.3 [指针数组与指向指针的指针](#23-指针数组与指向指针的指针)
    * 2.4 [内存的动态分配与释放](#24-内存的动态分配与释放)
    * 2.5 [void 与 const 修饰指针变量](#25-void-和-const-修饰指针变量)
   
* 3 [结构体与列表](#3)

    * 3.1 [结构体的建立](#31-结构体的建立)

    * 3.2 [结构体的应用](#32-结构体的应用)
    * 3.3 [typedef 定义类型名](#33-typedef-定义类型名)
    * 3.4 [链表](#34-链表)
   
* 4 [文件操作](#4)

    * 4.1 [文件的打开与关闭](#41-文件的打开与关闭)

    * 4.2 [文本文件输入输出](#42-文本文件输入输出)
    * 4.3 [文件出错检测方法](#43-文件出错检测方法)
    * 4.4 [多文件操作](#44-多文件操作)
    * 4.5 [操作简单二进制文件](#45-操作简单二进制文件)
    * 4.6 [读写结构体文件](#46-读写结构体文件)
    * 4.7 [随机访问文件](#47-随机访问文件)
   
* 5 [类的基础部分](#5)

  * 5.1 [类的基本概念](#51-类的基本概念)

  * 5.2 [类的多文件组织方式](#52-类的多文件组织方式)
  * 5.3 [构造函数与析构函数](#53-构造函数与析构函数)
  * 5.4 [重载构造函数](#54-重载构造函数)
   
* 6 [类的高级部分](#6)

  * 6.1 [静态数据成员](#61-静态数据成员)

  * 6.2 [静态成员函数](#62-静态成员函数)
  * 6.3 [友元函数](#63-友元函数)
  * 6.4 [对象的赋值问题](#64-对象的赋值问题)
  * 6.5 [什么是拷贝构造函数](#65-什么是拷贝构造函数)
  * 6.6 [调用拷贝构造函数的情况](#66-调用拷贝构造函数的情况)
  * 6.7 [赋值运算符重载与this指针](#67-赋值运算符重载与this指针)
  * 6.8 [双目运算符重载](#68-双目运算符重载)
  * 6.9 [单目运算符重载](#69-单目运算符重载)
  * 6.10 [关系运算符重载](#610-关系运算符重载)
  * 6.11 [流操作符重载](#611-流操作符重载)
  * 6.12 [类型转换运算符重载](#612-类型转换运算符重载)
  * 6.13 [下标运算符\[\]重载](#613)
   
* 7 [类的继承、多态、虚函数](#7)

  * 7.1 [继承](#71-继承)

  * 7.2 [保护成员和类的访问](#72-保护成员和类的访问)
  * 7.3 [保护成员和类的访问](#73-保护成员和类的访问)
  * 7.4 [初始化列表的作用](#74-初始化列表的作用)
  * 7.5 [覆盖基类的函数成员](#75-覆盖基类的函数成员)
  * 7.6 [虚函数与纯虚函数](#76-虚函数与纯虚函数)
  * 7.7 [多重继承与多继承](#77-多重继承与多继承)
  * 7.8 [类模板](#78-类模板)
   
* 8 [异常处理](#8)
   
* 9  [标准模板STL](#9)

  * 9.1 [STL概述](#91-stl-概述)

  * 9.2 [容器](#92-容器)
  * 9.3 [迭代器](#93-迭代器)
  * 9.4 [算法](#94-算法)
    
    
---

## <span id="1">1 字符串与指针</span>

### 1.1 处理字符与字符串

* 求字符串的长度
  ```cpp
  char name[10] = {'T', 'o', 'm', '\0', 'P', 'e', 't', 'e', 'r', '\0'};
  cout << strlen(name) << sizeof(name) << endl; 
  ```
  注意：求字符串长度时，到'\0'就会结束

* 字符串的拷贝
  
  **方式一**
  ```cpp
  char* strcpy(char s1[], char s2[])
  ```
  例如
  ```cpp
  char src[80] = {"I am a student"};
  char dst[80];
  strcpy(dst, src);
  ```
  注意：不能使用‘=’号进行直接赋值

  **方式二**
  ```cpp
  char* strncpy(char s1[], const char s2[], int len)
  ```
  例如
  ```cpp
  char src[80] = {"I am a student"};
  char dst[80];
  strncpy(dst, src, 10);
  dst[10] = '\0';
  ```
  注意：必须加上'\0'字符串结束标志

* 字符串的连接
  ```cpp
  char* strcat(char s1[], const char s2[], int len)
  ```
  将s2字符串连接到s1的尾部，修改了s1，返回的是s1的首地址

  注意：s1的空间要足够大
  
  例如：
  ```cpp
  char s1[20] = "You";
  char s2[20] = "&Me";
  strcat(s1, s2);
  ```

* 字符串的比较
  
  **方式一**
  ```cpp
  int strcmp(const char s1[], const char s2[])
  ```
  比较两个字符串的大小，就是从左到右逐个比较对应字符的ASCII码

  若s1 > s2，则返回1

  若s1 < s2，则返回-1

  若s1 = s2，则返回0

  **方式二**
  ```cpp
  int strncmp(const char s1[], const s2[], int len)
  ```
  比较两个字符串的前len个字符，若字符串s1或者s2的长度小于len，则与strcmp无异

  例如：
  ```cpp
  char s1[10] = "China";
  char s2[10] = "Chinese";
  cout << strncmp(s1, s2, 5) << endl;//输出结果为-1
  ```

* 字符串的大小写转换
  
  **大写变小写**
  ```cpp
  char* strlwr(char s[])
  ```
  **小写变大写**
  ```cpp
  char* strupr(char s[])
  ```

* 字符串的子串查找
  ```cpp
  char* strstr(const char s1[], const char s2[])
  ```
  如果字符串s1包含要查找的子串s2，则返回s1在s1中第一次出现的地址，否则直接返回NULL

* 字符串转换为整数的函数
  ```cpp
  int atoi(const char str[])
  ```
  例如：
  ```cpp
  char s1[80] = "789123",
  s2[80] = "789X123",
  s3[80] = "X123";
  int i = atoi(s1);//789123
  int j = atoi(s2);//789
  int k = atoi(s3);//0
  ```
  转换成别的数据类型就自己类比啦

  atof，atod...

* 整数转换为字符串
  ```cpp
  char* itoa(int value, char str[], int radix)
  ```
  例如：
  ```cpp
  int n = 123;
  char s1[20], s2[20];
  itoa(n, s1, 3);//处理3进制
  itoa(n, s2, 10);//处理10进制
  ```

### 1.2 标准C++的String类

* 包含的头文件
  ```cpp
  string
  ```

* 读取整行
  ```cpp
  string name;
  getline(cin, name);
  ```
  注意：要和char类型做区分
  ```cpp
  char name[10];
  gets(name);
  cin.get(name, 10);
  cin.getline(name, 10);
  ```

* string对象的比较
  string对象也可以与字符串比较，例如
  ```cpp
  string name1 = "John";
  char name2[10] = "Jone";
  cout << (name1 > name2);//0
  cout << (name1 < name2);//1
  cout << (name1 == name2);//0
  ```

* string对象的初始化
  ```cpp
  string test1;    //空串
  string test2 = "内容"; //使用=
  string test3("内容");   //使用引用字符数组作为参数传给构造函数
  string test4(test2); //用一个string初始化另一而string
  string test5(test2,pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
  string test6 = test2 + "内容" + test3 //混合初始化
  string test7 = test2.substr(pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
  string test8 = test2.substr(); //参数列表为空则会拷贝test2的整个对象（复制test2的简便方法）
  string test9(num,ch); //拷贝num个字符型ch到test9
  ```

* string类型常用的操作符
  ```cpp
  =, assign() //赋以新值
  swap() //交换两个字符串的内容
  +=, append(), push_back() //在尾部添加字符
  insert() //插入字符
  erase() //删除字符
  clear() //删除全部字符
  replace() //替换字符
  + //串联字符串
  ==, !=, <, <=, >, >=, compare() //比较字符串
  size(), length() //返回字符数量
  max_size() //返回字符的可能最大个数
  empty() //判断字符串是否为空
  capacity() //返回重新分配之前的字符容量
  reserve() //保留一定量内存以容纳一定数量的字符
  [ ], at() //存取单一字符
  >>,getline() //从stream读取某值
  << //将谋值写入stream
  copy() //将某值赋值为一个C_string
  c_str() //将内容以C_string返回
  data() //将内容以字符数组形式返回
  substr() //返回某个子字符串
  find() //查找字符
  begin() end() //提供类似STL的迭代器支持
  rbegin() rend() //逆向迭代器
  get_allocator() //返回配置器
  ```

### 1.3 指针的概念、指针变量的定义和使用

* 指针变量就是存放地址的变量
  
* 定义指针变量
  例如：
  ```cpp
  int* pInt;
  ```
  注意：
   
    * 指针不知向内存的0号单元，若指针变量值为0或者NULL，则表示空指针
  
    * 地址值与整型数值不同

    * 无论何种类型的指针都占用4个字节的内存空间
  

* 运算符*与&
  
  *：通过指针访问所指变量的数值

  &：访问指针内储存的地址

* 引用指针变量
  ```cpp
  int x = 30, y = 90;
  int *p1 = &x, *p2 = &y, t;
  t = *p1;
  *p1 = *p2;
  *p2 = t;
  ```
  上述例子实现了p1与p2指向变量的值的交换

### 1.4 指针与数组

* 访问数组的方式
  
  * 下标形式
  
  * 指针形式

* 两种类型数组

  * 全局数组和静态数组：在静态储存区中被创建
  
  * 局部变量：在栈上被创建

* 数据名对应一块内存，其地址与容量在其生命周期内保持不变，只有数组的内容可以改变
* 指针可以指向任意类型的内存块，其特征是“可变”
* 指向一维数组元素的指针
  
  数组名代表该数组的开始地址，数组名即时一个指针常量，例如
  ```cpp
  int a[10], *p;
  p = a;
  p = &a[0];//二者等价
  ```

* 指针比较

  指向同一个数组的两个指针可以进行比较

  逆序存放的代码
  ```cpp
  for(p1 = set, p2 = set+length-1; p1 < p2; p1++, p2--) {
    t = *p1;
    *p1 = *p2;
    *p2 = t;
  }
  ```

* 指针变量之间的加法无意义

* 指向二维数组元素的指针
  
  二维数组元素a[i][j]的表示
  ```cpp
  //表示地址
  &a[i][j]
  a[i]+j
  *(a+i)+j
  
  //表示数值
  a[i][j]
  *(a[i]+j)
  *(*(a+i)+j)
  (*(a+i))[j]
  ```
  注意：a[0] == a[0][0]

  一个通用的二维数组的输出例子
  ```cpp
  void Print(int* p, int row, int col) {
    int i;
    for(i = 0; i < row*col; i++, p++) {
      if(i % col == 0) {
        cout << end;
      }
      cout << setw(4) << *p;
    }
    cout << endl;
  }
  ```

---

## <span id="2">2 指针与函数</span>

### 2.1 参数的传递方式

* 基本类型的变量作函数形参
  
  交换变量x与y的值，采用基本类型的变量做函数形参
  ```cpp
  void swap(int a, int b) {
    int t;
    t = a;
    a = b;
    b = t;
  }
  ```
  这是单向的值传递，形参的变化不会影响实参

* 引用类型作为函数形参

  交换变量x与y的值，采用引用类型做函数的形参
  ```cpp
  void swap(int& a, int& b) {
    int t;
    t = a;
    a = b;
    b = t;
  }
  ```
  通过定义被调用中的参数为引用类型，将主调函数的值改变

* 指针类型作为函数形参

  交换变量x与y的值，采用指针类型做函数形参
  ```cpp
  void swap(int* px, int* py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
  }
  ```
  通过定义被调用函数中的参数为指针类型，通过间接存取将主调函数的值改变

  注意：指针类型做参数形参的另一种形式是数组名做函数参数

### 2.2 返回指针的函数及指向函数的指针

* 指针型函数
  
  一个函数的返回值是某种数据类型的地址值就是指针型函数
  ```cpp
  int* function(int x, int y) {
    return x+y;
  }
  ```

* 函数指针
  
  函数的入口地址。函数指针变量就是指向函数入口地址的变量。
  ```cpp
  int (*fun)(int , int);
  int max(int x, int y) {
    return x > y?x : y;
  }
  fun = max;
  ```
  用法示例
  ```cpp
  int process(int x, int y, int (*fun)(int, int)) {
    return fun(x, y);
  }
  ```

### 2.3 指针数组与指向指针的指针

* 指针数组
  
  一个数组里面所有的元素都是指针变量称为指针数组

* 指针数组与数组指针的本质区别就是*与[]的优先级顺序不同

  ```cpp
  int (*p)[M]; //p是一个数组指针，一个行指针，指向拥有M个元素的一维数组
  int* p[M]; //p是一个指针数组，包含有M个指针
  ```

* main函数的参数
  
  在main()函数头部声明的格式为
  ```cpp
  int main(int argc, char* argv[])
  int main(int argc, char** argv)
  //argc表示命令行中字符串的个数
  //argv[]指向命令行中的各个字符串
  ```
  举个栗子，通过命令行参数计算输入数据的和
  ```cpp
  int main(int argc, char* argv[]) {
    int sum, i;
    cout << "Command name:" << argv[0] << endl;
    for(sum = 0, i = 1; i < argc; i++) {
      sum += atoi(argv[i]);
    }
    cout << "Sum is:" << sum << endl;
  }
  ```

* 指向指针的指针
  
  举个栗子
  ```cpp
  int x, *p = &x, **pp = p;
  ```

### 2.4 内存的动态分配与释放

* 变量存储空间的分配是系统完成的，不需用户干预
  
  * 静态变量：编译时分配空间
  
  * 动态变量：系统运动时分配空间

* 程序动态申请空间是由用户在编程时安排的
* 申请多少空间由运行时情况而定，一般通过指针访问空间
* new用于动态申请储存空间，delete用于释放new申请的存储空间
  ```cpp
  //分配单个元素空间
  int* iptr;
  iptr = new int;
  *iptr = 25;
  //也可以这样
  iptr = new int(25);
  delete iptr;
  //分配一片连续的空间
  int* a;
  a = new int[100];
  delete []a;
  ```
  注意：如果函数的参数是一个指针，不要用指针去申请动态内存，否则会因为申请的空间无法释放而造成内存泄漏

### 2.5 void 和 const 修饰指针变量

#### 2.5.1 void修饰指针变量

* void修饰指针
  
  void修饰指针代表是一种不确定类型的指针

* 任何类型的指针都可以直接赋给它，无需类型转换

  ```cpp
  void* p1;
  int* p2;
  p1 = p2;
  ```

* 不能对void指针进行算数操作

#### 2.5.2 const修饰指针变量
  
* 指向常量的指针
  
  可以改变指针所指的空间，但不可以通过指针改变现在所指的内容

  ```cpp
  int i = 6;
  const int* p1 = &i;
  const int m = 16;
  *p1 = 16; //wrong
  p1 = &m; //true
  ```

* 常量指针

  可以改变指针所指向空间中的内容，但是不能改变指针的指向

  ```cpp
  char stringA[10] = "abcd", stringB[10] = "xyz";
  char* const sp = atringA;
  sp = stringB; //wrong
  *(sp+1) = 't'; //true
  ```

* 指向常量的指针常量

  既不可以修改指针所指的内容又不可改变指针的指向

---

## <span id="3">3 结构体与列表</span>

### 3.1 结构体的建立

* 结构体就是通过定义一种数据类型，把不同的数据作为一个整体来处理

* 结构体是一种由程序员创建的抽象数据类型

* 先定义结构体
  ```cpp
  struct<结构体名称> {
    <成员列表>
  }; //这里不要忘记了;号
  ```

* 再定义变量
  ```cpp
  student John, Mary;
  struct student John, Mary;
  ```

* 也可以使用无结构体名构造一次性结构体
  ```cpp
  struct {
    int ID;
    char name[10];
  }John, Mary;
  ```

* 初始化结构体类型的变量

  用{}括起来的值对结构体变量进行初始化，例如
    ```cpp
    student John = {666, "Joe"};
    ```

  用同类型的结构体变量初始化另外一个结构体变量
    ```cpp
    student Merry = John;
    ```

* 结构体类型变量及其成员的引用

  引用结构体变量的成员
  ```cpp
  John.ID = 2333;
  ```

  整体引用结构体变量
  ```cpp
  student John = {...};
  student Merry;
  Merry = John;
  ```

  注意

  * 不能将结构体作为一个整体进行输入或者输出

  * 结构体变量可以用作函数的参数，属于按值传递

  * 函数可以返回一个结构体变量

### 3.2 结构体的应用

* 使用结构体变量作为函数参数的效率较低，因为结构体作为形参需要赋值

* 结构体数组与指针

  定义结构体数组和初始化
  ```cpp
  student studentList[4];
  student studentList[4] = {{...}, {...}, {...}, {...}};
  ```

  使用结构体数组
  ```cpp
  //引用元素
  for(int i = 0; i < 4; i++) {
    cout << studentList[i].name;
  }
  //指针
  student *ps;
  ps = stud;
  ps++;
  ```

### 3.3 typedef 定义类型名

* 语法格式
  ```cpp
  typedef <原类型名> <自定义的类型名>
  ```

  栗子：
  ```cpp
  typedef char NAME[100];
  NAME Joe;
  //等价于下面
  char Joe[100];
  ```

* 注意typedef与#define的不同

  * 关键字typedef在编译阶段有效，具有类型检查的功能

  * #define是宏定义，发生在预处理阶段，只会进行简单的字符替换，不做任何检查

  * #define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用

  * typedef则具有自己的作用域

* 用typedef定义新类型名
  
  * typedef只能用于为已知数据类型名定义新的类型名，并没有增加新的数据类型

  * typedef用于软件移植
  
    比如定义一个叫REAL的浮点类型，在目标平台一上，让它表示最高精度的类型为
    ```cpp
    typedef long double REAL;
    ```

    而在不支持long double的第二平台上，改为
    ```cpp
    typedef double REAL;
    ```

    在连double都不支持的平台上，改为
    ```cpp
    typedef float REAL;
    ```

### 3.4 链表

* 链表的引入

  * 数据空间是连续的
  
  * 实际应用无法确定数组的大小
  * 定义足够大————空间浪费

* 链表的结构
  ```cpp
  struct student {
    int ID;
    char name[20];
    student* next; //链表与结构体的区别
  };
  ```

* 单向链表
  
  带有头节点的单向链表

  不带头节点的单向链表

* 链表的应用示例
  ```cpp
  #include "stdafx.h"
  #include <iostream>
  #include <iomanip>
  using namespace std;
  typedef struct node
  {
	  int data;
	  node *next;
  } NODE;
  NODE* initlist()
  {
      NODE *head;
      head = new NODE;
	  head->next = NULL;
	  return head;
  }
  
  NODE *create()
  {
	  NODE *p1, *p2, *head;
	  int a;
	  p2 = head = initlist();
	  cin >> a;
	  while ((a!=-1))
	  {
		  p1 = new NODE;
		  p1 -> data = a;
		  p2 -> next = p1;
		  p2 - p1;
		  cin >> a;
	  }
	  p2->next = NULL;
	  return(head);
  }
  void print(NODE* head)
  {
	  NODE *p;
	  p = head->next;
	  if (p != NULL)
	  {
		  cout << "Output list : ";
		  while (p != NULL)
		  {
			  cout << setw(5) << p->data;
			  p = p->next;
		  }
		  cout << "\n";
	  }
  }
  NODE* search(NODE* head, int x)
  {
	  NODE *p;
	  p = head->next;
	  while (p != NULL)
	  {
		  if (p->data == x)
			  return p;
		  p = p->next;
	  }
	  return NULL;
  }
  NODE *insert(NODE *head, NODE *s)
  {
	  NODE* p;
	  p = head;
	  while (p->next != NULL&&p->next->data < s->data)
		  p = p->next;
	  s->next = p->next;
	  p->next = s;
	  return head;
  }
  NODE *create_sort()
  {
	  NODE* p, *head = NULL;
	  int a;
	  head = initlist();
	  cin >> a;
	  while (a != 1)
	  {
		  p = new NODE;
		  p->data = a;
		  head = insert(head, p);
		  cin >> a;
	  }
	  return head;
  }
  NODE *delete_one_node(NODE *head, int num)
  {
	  NODE* p, *temp;
	  p = head;
	  while (p->next != NULL&&p->next ->data!=num)
		  p = p->next;
	  temp = p->next;
	  if (p->next != NULL)
	  {
		  p->next = temp->next;
		  delete temp;
	  }
	  else cout << "NOT found";
	  return head;
  }
  void free_list(NODE *head)
  {
	  NODE *p;
	  while (head)
	  {
		  p = head;
		  head = head->next;
		  delete p;
	  }
  }
  
  int main()
  {
	  //return 1;
	  NODE *st, *head = NULL;
	  int num; char c;
	  cout << "\n creat a list:\n";
	  head = initlist();
	  while (1)
	  {
		  cout << "\n\t D:Delete I:Insert P: Print S:Search E: Exit\n";
		  cin >> c;
		  switch (toupper(c))
		  {
		  case'I':
			  st = new NODE;
			  cout << "please input a number to be inserted:";
			  cin >> st->data;
			  insert(head, st);
			  break;
		  case 'D':
			  cout << "please input a number to be deleted:";
			  cin >> num;
			  delete_one_node(head, num);
			  break;
		  case 'S':
			  cout << "please input a number to be search:";
			  cin >> num;
			  if (search(head, num) != NULL)
			  {
				  cout << "it is in the list. \n";
			  }
			  else
				  cout << "It is not in the list. \n";
			  break;
		  case 'P':
		  	print(head);
			  break;
		  case 'E':
			  free_list(head);
			  exit(0);
		  default:
			  break;
		  }
	  }
	  return 0;
  }
  ```

---

## <span id="4">4 文件操作</span>

### 4.1 文件的打开与关闭

* 文件流类型

  ```cpp
    #include<fstream> //文件流头文件
    ifstream a//输入文件流，只读取文件流
    ofstream b//输出文件流，只写入文件流
    fstream c//文件流
    ```

* 文件使用过程

  #### **打开文件**

    * 开启方式

    ```cpp
    ifstream inputFile;
    inputFile.open("d:\\costumer.dat");
    //or
    char fileName[20];
    cin>>fileName;
    inputFile.open(fileName);
    ```
    *  使用fstream对象时，第二个参数用于表明文件的打开方式



    ```cpp
    dataFile.open(“info.dat”, ios::out);//只能用于写
    dataFile.open(“info.dat”, ios::in);//只能用于读
    dataFile.open(“info.dat”, ios::noreplace);//表明如果文件已存在，则不能打开该文件，如果省略该模式，文件内容将被刷新
    ios::nocreate//如果文件不存在，则不能创建
    ios::app//追加模式
    ios::ate//如果已存在，直接跳转到文件尾部
    ios::binary//二进制方式
    ios::trune//如果文件存在，删除其内容

    //上面展示的是先定义对象，再打开文件
    //也可以在定义流对象时直接打开文件
    fstream dataFile("name.dat",ios::in|ios::out);

    ```

    * 测试文件是否打开成功
    ```cpp
    ifstream dataFile
    dataFile.open("cust.dat",ios::in);
    if(!dataFile)
    {
      cout<<"fail to open";
      exit(0);
    }
    ```


  #### **关闭文件**

  ```cpp
  dataFile.close();
  ```
    * 为何要关闭文件
      
       文件缓冲区是一块小的内存空间

      操作系统限制同时打开的文件数量

  


### 4.2 文本文件输入输出

* 使用<<向一个文件写入信息
  ```cpp
  #include<iostream>
  #include<fstream>
  #include<cstdlib>
  using namespace std;

  int main()
  {
    fstream dataFile;
    dataFile.open("demoFile.txt",ios::out;

    dataFile<<”Confucius\n”;//写入一个单词，换行
    dataFile<<”Mo-tse\n”;//写入，换行

    dataFile.close();

    return 0;
  }
  ```

* 文件的格式化输出
  ```cpp
  #include<iostream>
  #include<fstream>
  #include<cstdlib>
  using namespace std;

  int main()
  {
    fstream outFile(“number.txt”,ios:out);
    int nums[3][3]={1234,3,567,34,8,6789,124,2345,89};

    for(int row=0;row=3;row++)//向文件输出三行
    {
      for(int col=0;col<3;col++)
      {
         outFile<<setw(10)<<nums[row][col]<<” ”;
      }
       outFile<<endl;
    }
    outFile.close();
  }
  ```
* 检测文件结束
  
  eof()成员函数：检测文件是否已经结尾，无数可读。
  ```cpp
  int main()
  {
    fstream dataFile;
    char name[81];
    dataFile.open(“demofile.txt”,ios::in);
    while(!dataFile.eof())
    {
      dataFile>>name;
      if(dataFile.fail())
      break;
      cout<<name<<”\n”;
    }
    dataFile.close();
  }
* 采用函数成员读写文件

  **采用>>读文件的缺陷**：空白字符(空格、跳格、换行、回车)是数据之间的分界符，采用>>操作符进行读取时，会忽略空白字符。

#### **getline**成员函数：
  ```cpp
    dataFile.getline(str,81,’\n’)
  ```

**str**: 从文件中读取的数据将存储在该空间中

**81**：从文件中最多能读取80个字符

**’\n’界符**：如果在读满最大字符之前，遇到了界符，那么将停止读取（注意：该参数可选）
  
  ```cpp
  #include<iostream>
  #include<fstream>
  #include<cstdlib>
  using namespace std;

    int main()
    {
      fstream readFile;
      char input[81];

      readFile.open(“myTextFile.txt”,ios::in);

      while(!readFile.eof())
      {
        readFile.getline(input,81);//从输入获取最多81个字符进入readFile
        if(readFile.fail())
        {
          break;
        }
        cout<<input<<endl;
      }
      readFile.close();
      return 0;
    }
  ```

#### get成员函数

  * 例如：inFile.get(ch);
  
#### put成员函数

  * 例如：inFile.put(ch);
```cpp
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
  fstream dataFile("sentence.txt",ios::out);
  char ch;

  while(cin.get(ch))
  {
    if(ch=="!")
    {
      break;
    }
    dataFile.put(ch);
  }

  dataFile.close();
  return 0;
}
```


### 4.3 文件出错检测方法

* 出错检测

  #### 流对象的标志位

  * 例如
  
  |流对象|内容|
  |:-|:-|
  |ios::eofbit|当遇到了输入流的尾部时，设置该位|
  |ios::failbit|当操作失败时，设置该位|
  |ios::hardfail |当出现不可恢复错误时，设置该位
  |ios::badbit |当出现无效操作时，设置该位
  |ios::goodbit |当上述所有标记都未设置时，设置该位，表明流对象处于正常状态

* 函数检测状态位

  |函数名称|意义|
  |:-|:-|
  |eof（） |如果设置了eofbit状态位，该函数将返回true否则返回false
  |fail（） |如果设置了failbit或hardfail状态位，返回true否则返回false
  |bad () |如果设置了badbit状态位，该函数将返回true否则返回false
  |good ()|如果设置了goodbit状态位，返回true否则返回false
  |clear () |调用该函数，将清楚所有状态位|

**实例**
```cpp
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void showstate(fstream &);
int main()
{
  int num=10;
  fstream testFile("stuff.dat",ios::out);
  if(testFile.fail())
  {
    cout<<"打开文件失败!";
    exit(0);
  }
  cout<<”向文件中写数据!\n”;

  testFile<<num;
 showState(testFile);//第1次测试
 testFile.close();
 testFile.open(“stuff.dat”,ios::in);
 if(testFile.fail())
 {
 cout<<”打开失败\n”；
 exit(0);
 }
 testFile>>num;
 showState(testFile);//第2次测试
 test>>num;
 showState(testFile);//第3次测试
 testFile.close();
}

 void showState(fstream &file)
 {
 cout<<”当前文件的状态为：\n”;
 cout<<”eof bit:”<< file.eof()<<” ”;
 cout<<”fail bit:”<<file.fail()<<” ”;
 cout<<”bad bit:”<<file.bad()<<” ”;
 cout<<”good bit:”<<file.good()<<endl;
 file.clear();//清除出错标记位
}
```
  

### 4.4 多文件操作

* **实例**
```cpp
#include<iostream>
 using namespace std;
 #include<fstream>
 int main()
 {
 ifstream inFile;
 ofstream outFile(“out.txt”);
 char fileName[81],ch,ch2;
 cout<<”请输入文件名：”；
 cin>>fileName;
inFile.open(fileName);
if(!inFile)
{
   cout<<”打开失败”<<fileName<<endl;
   exit(0);
 }
while(!inFile.eof) 
 { 
   inFile.get(ch); 
  if(inFile.fail()) 
  break; 
  ch2=toupper(ch); 
  outFile.put(ch2); 
} 
inFile.close(); 
outFile.close(); 
 }
```
### 4.5 操作简单二进制文件

* **二进制文件**

  二进制文件是按照在内存中存储的形式存储，不是按照ASCII纯文本方式存储，文件中
  存储的数据是非格式化的。

#### 以二进制打开文件
```cpp
file.open("stuff.dat",ios::out|ios::binary);//缺少binary则以文本打开
```
#### 二进制文件的读写函数（仅如下两个）、
```cpp
file.read((char *)buffer,sizeof(buffer));
file.write((char *)buffer,sizeof(buffer));
```
**实例**
```cpp
 void main()
 {
   fstream file;
   int buffer[10] = {1,2,3,4,5,6,7,8,9,10};
   file.open("a1.txt", ios::out | ios::binary);// 创建一个二进制文件
   file. write ((char*)buffer,sizeof (buffer));
   file.close();
   file.open("a1.txt", ios::in|ios::binary);
   file.read ((char*)buffer; sizeof(buffer));
   for(int count = 0; count < 10; count++)
   cout<<setw(6)<<buffer [count];
   file.close();
   file.open(“a2.txt”, ios::out); // 创建文本文件
   for(int i = 0; i < 10; i++)
     file<<buffer[i];
   file.close();
 }
```

### 4.6 读写结构体文件

* 读写结构体记录

  结构体数据可以采用定长块存储到文件中

  因为结构体中可以包含不同类型的数据，所以当打开这种类型文件时，必须以二进制方式
打开

* **实例**
  ```cpp
  #include <iostream>
  using namespace std;
  #include <fstream>
  #include <cstdlib>
  #include <cctype>
  struct Info
  {
  char name[21];
  int age ；
  char address [51];
  char phone[14];
  char email[51];
  }；

  int main()
  {
    fstream people("people.dat",ios::out|ios::binary);
    Info person;
    char again;
    if(people.fail())
    {
      cout<<"打开文件people.dat出错! \n";
      exit(0);
    }

    do
    {
       cout<< ”请输入数据:\n” ；
       cout<<"姓名:"; cin.getline(person.naine, 21);
       cout<<"年龄:"; cin>>person.age;
       cin.ignore(); // 略过换行符,why?
       cout<<"联系地址:";cin.getline(person.address, 51);
       cout<<"联系电话:";cin.getline(person.phone, 14);
       cout<<"E-mail:" ; cin.getline(person.email, 51);
       people.write(( char *)&person, sizeof(person));
       cout<<"还要再输入一个同学的数据吗？";
       cin>>again;
    }

    while(toupper(again)='Y')
    {
      people.close();
    }
    
    while(!people.eof())
    {
    	people.read((char *)&person, sizeof(person));
	if(people.fail())
	{
		break;
	}
    }
    
    people.close();
  }
  ```

### 4.7 随机访问文件

* **seekp 和 seekg函数**：
  
  seekp 函数用于输出文件（写，put）

  seekg 函数用于输入文件（读，get）
  ```cpp
  file.seekp(20L,ios::beg);//把file对象相对于文件头向后偏移20个字节

  //文件随机访问模式
  ios::beg;//从文件头开始计算偏移量
  ios::end;//从文件尾开始计算偏移量
  ios::cur;//从当前位置开始计算偏移量
  ```
* **seek实例**:
  ```cpp
  #include<iostream>
  #include<fstream>
  #include<cstdlib>
  using namespcae std;

  int main()
  {
    fstream file("digit.txt",ios::in);//假设内容是1234567890
    char ch;
    if(!file) exit(0);
    file.seekg (1L, ios::beg );//调整到2位置
    file.get(ch); cout<<ch << endl;
    file.seekg(-3L, ios::end );//调整到8位置
    file.get(ch); cout<< ch << endl;//自动后移
    file.seekg(1L, ios::cur );//偏移到0
    file.get(ch); cout<< ch << endl;
    file.close();
  }
  ```
* **tellp 和 tellg 函数**:
  
  tellp用于返回写位置

  tellg用于返回读位置

* **tell实例**:
  ```cpp
  #include <iostream>
  using namespace std;
  #include <fctream>
  #include <cstdlib>
  #include <cctype>
  int main()
  {
    fstream file(“digit.txt”,ios::in);//假设内容是1234567890
    long offset;
    char ch, again;
    if(!ffle)
    {
      exit(0);
    }
     do
    {
      cout<<”当前位置为:”<< file.tellg( )<<endl; 
      cout<<”输入一个偏移量:”； 
      cin>>offset; 
      file.seekg (offset, ios::beg); 
      file.get(ch); 
      cout<<"当前字符是:"<< ch; 
      cout<<”\n是否继续?”； 
      cin>>again; 
    } 
    while(toupper(again) = ‘Y’);
    file.close();
  }
  ```

---

## <span id="5">5 类的基础部分</span>

### 5.1 类的基本概念

* **过程化程序设计的缺陷**
  
  1、大量的全局变量;

  2、程序复杂:程序员难以理解成百，上千的函数;

  3、程序难以进行修改和扩充。

  4、过程化设计是以过程为中心(函数)。

&nbsp;
* 类是一种用户自定义类型，声明形式为
  ```cpp
  class 类名
  {
    内容;
  }
  ```
* **类的内容**
  
  #### 数据类型
  public：可以在类外通过对象访问

  private：只能通过类的成员函数访问

  protected：与private类似，但在继承时保持功能

&nbsp;
* **定义成员函数**:
  
  #### 方式一、在类内部定义
  ```cpp
  class Rectengle
  {
    private:
      float width;
      float length:
      float area;
    public:
      void setData(float w,float l)
      {
        width=w;

        length=l;
      }
      void calcArea( );
      float getWidth( );
      float getLength( );
      float getArea( );
  };
  ```
  #### 方式二、在类的外部定义
  ```cpp
  class Rectengle
  {
    private:
      float width;
      float length:
      float area;
    public:
      void setData(float,float);
      void calcArea( );
      float getWidth( );
      float getLength( );
      float getArea( );
  };

  void Rectangle::setData(float w, float l )
  {
    width=w;
    length=l;
  }
  float Rectangle::getWidth( )
  {
    return width;
  }
  ```

* **定义对象**:
  #### 实例
  ```cpp
  int main()
  {
    Rectangle box;
    float wide,boxLong;

    cout <<"请输入长和宽?";
    cout <<"请输入长和宽?";
    box.setData(wide, boxLong);
    box.calcArea( );

    cout << "矩形的数据:\n";
    cout << "宽: "<< box.getWidth() << endl;
    cout << "长:" << box.getLength( ) << endl;
    cout << "面积: " << box.getArea( ) <<endl;
  }
  ```


### 5.2 类的多文件组织方式
* **组织方式**:
  
  类的定义**存储在头文件**里(类定义文件)

  成员**函数定义存储在.cpp文件**(类的实现文件)

  应用程序通过#include包含头文件，将类的实现文件和主程序进行联编，从而
生成一个完整的程序

&nbsp;
### 5.3 构造函数与析构函数
* **定义**
  
  构造函数：是一个函数成员，在对象创建时，采用给定的值，自动调用该
  函数将对象中的数据成员初始化

  析构函数：也是一个函数成员，当对象终止时，将自动调用该函数进行
  “善后”处理

&nbsp;
* **构造函数的特点**
  
  1.构造函数是与类同名的函数成员;

  2.没有返回值类型，也没有void;

  3.如果构造函数没有参数，则称为缺省构造函数;

  4.如果程序中未声明，则系统自动生成一个缺省形式的构造函数;

  5.构造函数允许为内联函数、重载函数、带缺省形参值的函数。

* **构造函数实例**:
```cpp
class Invoiceltem
{
char *desc;
int units;
public:
InvoiceItem( )
{desc = new char [51]; }
void setInfo(char *dscr, int un)
{
strcpy(desc, dscr);
units = un;
}
char *getDesc( ) { return desc;}
int getUnits( ) { return units:}
};

int main()
{
Invoiceltem stock;//定义时候自动调用
stock.setInfo( "鼠标"
, 20);
cout << stock.getDesc( ) << endl;
cout << stock.getUnits( ) << endl;
}
```
  #### 指向对象的指针
  * InvoiceItem *ptr;

  * ptr=new InvoiceItem;//此时调用构造函数

&nbsp;
* **析构函数的特点**
  
  1、析构函数也与类同名，前面多一个波浪号(~)

  2、当一个对象终止时，系统自动调用析构函数对此对象做“善后”处理。

  3、与构造函数一样，析构函数也没有返回值类型。

  4、析构函数无参数。

  5、一个类只能有一个析构函数。

  6、delete对象时，将调用析构函数。

* **析构函数实例**
```cpp
class Invoiceltem
{ char *desc;
int units;
public:
InvoiceItem( )
{desc = new char [51];
cout << “构造函数\n;} ~InvoiceItem( )
{delete []desc；
cout << “析构函数\n“;}
//其他函数略

int main()
{
Invoiceltem stock;
stock.setInfo( "鼠标"
, 20);
cout << stock.getDesc( ) << endl;
cout << stock.getUnits( ) << endl;
}
```

* **带参数构造函数**
  
  常常需要把一些数据传递给构造函数，用于初始化对象的成员。

  构造函数可以有缺省参数。

  **实例**
  ```cpp
  class Sale
  {
   float taxRate,total;
   public:
   Sale(float rate)
   {
     taxRate=rate;
   }
  }
  ```

### 5.4 重载构造函数
一个类中可以定义多个构造函数
* **缺省构造函数的表现形式**
  
  1、如果类中没有定义构造函数，系统将提供一个无参构造函数(属缺省构造函数),该函数不实现任何功能。如果用户自定义了一个构造函数，那么系统缺省的构造函数将失效。

  2、如果类中定义有无参的构造函数，那么该构造函数也是缺省的构造函数。

  3、如果类中定义有带参的构造函数，并且所有形参均具有缺省值，那么该构造函数也属于缺省的构造函数。

  4、一个类只能有一个缺省构造函数，否则将产生二义性。
  
  出错实例：
  ```cpp
  class A;
  {
    int a;

    public:
    A(){a=0;}
    A(aa=1){a=aa;}//两构造函数产生歧义，因为有缺省值，也属于缺省构造函数
  }
  ```

&nbsp;
* **对象数组**
  #### 特点
  * 创建对象数组时，数组中**每个元素(对象)都将调用构造函数**。
  
  * 如果**没有**为数组元素指定**初始值**，元素便使用缺省值来初始化，即**调用缺省构造函数**。

  * 当数组中**每一个对象被删除**时，**都要调用一次析构函数**。

---

## <span id="6">6 类的高级部分</span>

### 6.1 静态数据成员
#### 特点
* 用关键字static声明；**同一个类中的所有对象都共享该变量**；
  
* 必须**在类外定义和初始化**，用(::)来指明所属的类。
  
* 静态变量**不依赖于对象而存在**，无论是否定义该类的对象，这种类型的变量都存在。
  
* 静态数据成员实际上是在类外定义的一个变量，它的生存期和整个程序的生存期一样，在**定义对象之前，静态数据成员就已经存在**。

* 实例
```cpp
class StaticDemo
{ 
  static int x ;
  int y ;
  public:
    void putx( int a){ x=a ; }
    void puty( int b ){ y=b ; }
    int getx( ) { return x ; }
    int gety( ) { return y ; }
} ;
int StaticDemo::x ;// 静态变量x将被StaticDemo类的所有对象共享

int main() 
{
StaticDemo obj1, obj2 ;
obj1.putx(5) ;
obj1.puty( 10) ;
obj2.puty(20 ) ;
cout << "x: "<< obj1.getx( ) << " " << obj2.getx( ) << endl ;
cout << "y: "<< obj1.gety( ) <<" "<< endl;
}

```

### 6.2 静态成员函数
#### 特点
* 静态函数成员是类中的一个函数，有**static**修饰。

* 静态函数成员和静态数据成员类似，在**对象生成之前也已经存在**。这就是说在对象
产生之前，静态的函数成员就能访问其它静态成员。

* **类外代码可以使用类名和作用域操作符来调用静态成员函数**。
  
* 静态成员函数**只能引用属于该类的静态数据成员**或**静态成员函数**。
  
* 对于静态的函数成员，是通过类名和作用域分辨符调用的。
  
* 也可以采用对象点的方式调用

* 实例
```cpp
class Budget
{ 
  static float corpBudget;//预算的总额
  float divBudget;//非静态成员
public:
  Budget( ) { divBudget = 0; }
  void addBudget( float b)
  { 
    divBudget += b;
    corpBudget += divBudget;
  }
  static void mainOffice( float );//静态的函数成员
  float getDivBudget( ) { return divBudget; }
  float getCorpBudget( ){ return corpBudget;}
};

float Budget::corpBudget = 0 ;//静态数据必须在类的外部进行定义和初始化

void Budget::mainOffice(float moffice)
{
corpBudget += moffice;//只能使用静态变量或其他静态函数或自己的局部变量
}

void main( )
{ 
float amount;
int i;
float bud;
cout << "Enter main office's budget request: ";
cin >> amount;
Budget::mainOffice(amount);//调用静态成员函数
Budget divisions[4]; //定义一个数组，一个总公司有4个子公司
for ( i = 0; i < 4; i++)
{ cout << "Enter the budget for Division ";
cout << (i + 1) << " " ;
cin >> bud;
divisions[i].addBudget(bud);
}
cout << "\n Here are the division budget :\n";
for ( i = 0; i < 4; i++)
{
cout << "\t 子公司" << (i + 1) << "\t 预算";
cout << divisions[i].getDivBudget( ) << endl;
}
cout<<''\t 公司总预算：'';
cout<< divisions[i].getCorpBudget( )<<endl;
```

### 6.3 友元函数
#### 特点
* 友元函数**不是类中的函数成员**，但它和类的函数成员一样，**可以访问类中定义的私有成员**。

* 友元函数**可以是一个外部函数**，也**可以是另外一个类的函数成员**。

* 若一个类为另一个类的友元，则此类的**所有成员都能访问对方类的私有成员**。

#### 声明方式
* friend 类型 函数名字(数据类型)

* 外部函数作为类的友元实例：
```cpp
class Point
{
int xPos, yPos ;
public:
Point(int xx=0, int yy=0 )
{ xPos=xx; yPos=yy; }
int GetXPos( ) { return xPos; }
int GetYPos( ) { return yPos; }
friend double Distance(Point &a, Point &b); //表面上看是类的成员函数
};

double Distance( Point & a, Point & b)//注意没有作用域分辨符
{
double dx=a.xPos-b.xPos;
double dy=a.yPos-b.yPos;
return sqrt(dx*dx+dy*dy);
}


```

* 类的成员函数作为另外一个类的友元实例
```cpp
class A;//超前引用
class B
{
  public: 
  void set(int x,A &o); 
} 
class A
{ 
  int data; 
  void show(){cout <<data<<endl;} 
  public: 
  friend void B::set(int x,A &o); //该函数是类A的友元，须在A后定义
}

void B::set(int x, A &o) 
{ 
  o.data=x;o.show();
 } 
 
void main()
{ 
  A a; 
  B b; 
  b.set(6,a); 
}
```

### 6.4 对象的赋值问题

  * 采用赋值运算符“=”可以将一个对象赋值给另外一个对象，或者采用一个对象初始化另外一个对象

  * 在缺省的情况下，这两个操作执行的是对象成员之间的拷贝，也被称为按位拷贝或浅拷贝

  * 通过赋值运算符进行对象赋值时，是把一个区域中的内容拷贝过来，覆盖另外一个区域，只影响值的变化，对内存区域没有任何影响
  * 赋值和初始化的区别：赋值出现在两个对象都已经存在的情况下，而初始化出现在创建对象时
  * 当采用一个对象初始化另外一个对象时，对象成员之间的赋值也是按位拷贝
  * 编译器会区分赋值与初始化，赋值的时候调用重载的赋值运算符，初始化的时候调用拷贝构造函数。若类中原来没有，则生成的默认构造函数只会简单地赋值类中的每一个成员
  
### 6.5 什么是拷贝构造函数

* 通常采用按位拷贝操作也能正常赋值，但当类成员变量含有指针时往往不能正常运行
  ```cpp
  class PersonInfo {
    char* name;
    int age;
  public:
    PersonInfo(char* n, int a) {
      name = new char[strlen(n)+1];
      strcpy(name, n);
      age = a;
    }
    ~PersonInfo() {...}
  };

  int main() {
    PersonInfo person1("Jones", 20);
    PersonInfo person2 = person1; //会导致两个name指向同一个区域
  }
  ```

  解决办法：引入拷贝构造函数，当采用一个对象初始化另一个对象时，将自动调用该函数
  ```cpp
  PersonInfo(const PersonInfo &Obj) {
    name = new char[strlen(Obj.name)+1];
    strcpy(name, Obj.name);
    age = Obj.age;
  }
  ```

### 6.6 调用拷贝构造函数的情况

* 用对象初始化同类的另一个对象
  ```cpp
  PersonInfo st2(st1), st3 = st1;
  ```

* 如果函数的形参时对象，当进行参数传递时将调用拷贝构造函数
* 理解：拷贝构造函数的参数一定是个引用，防止拷贝构造函数被调用后又实例化了一个对象，再次调用了拷贝构造函数，形成无限递归
* 如果函数的返回值是对象，函数执行结束时，将调用拷贝构造函数对无名临时对象初始化

### 6.7 赋值运算符重载与this指针

* 赋值运算符重载

 
  operator= 函数的参数是常引用，优点是:

  * 效率高：采用引用可以防止参数传递时生成对象拷贝，节省了对象初始化和析构的过程。
  
  * 可以防止函数无意间修改对象right的内容。
  
  * 符合赋值运算的常识。
  
  
  注意：如果对象中有指针成员，采用拷贝构造函数可以解决对象初始化问题，但并不能处理对象赋值。

  假设有一个类PersonInfo：
  ```cpp
  class PersonInfo  { char *name;  int age; }
  ```
  要进行一个类对另一个类的赋值：
  ```cpp
  PersonInfo p1,p2;//p1=p2 等价于 p1.operator=(p2)
  ```

  需要对赋值运算符进行重载：

  ```cpp
  void operator = (const PersonInfo &right)
  { 
    delete [ ] name; //先删除原来的name 
    name = new char[strlen(right.name) + 1]; 
    strcpy(name, right.name); 
    age = right.age;
  }
  ```
   
* this 指针
  
  this是一个隐含的内嵌指针，它指向调用成员函数的当前对象。

  例如：
  ```cpp
  PersonInfo &operator=(const PersonInfo &right) //第一个&：返回对象的引用，节省空间，提高效率
   { 
    delete [ ] name; 
    name = new char[strlen(right.name)+ 1]; 
    strcpy(name, right.name); 
    age = right.age; 
    return *this; 
   }
  ```

  • this指针是以隐含参数的形式传递给非静态的函数成员 
  
  • this可用于解决局部变量与成员变量同名的问题

  例如：
  
  ```cpp
  PersonInfo( char *name, int age ) 
  { 
    this->name = new char[ strlen( name ) + 1]; 
    strcpy( this->name, name ); 
    this->age = age; 
  }
  ```
### 6.8 双目运算符重载
  * 任何一个双目算术运算符 A 被重载以后，当执行二元运算时：
  
    Obj1 A Obj2 完全等价于：Obj1.operator A( Obj2 )
  
    双目算术运算符有+、-、*、/、+= 等

    例如：对+运算符进行重载
    ```cpp
    class FeetInches 
    {  
      int feet, inches;
    public:
      FeetInches operator + (const FeetInches &);//const使得程序无法修改参数，&用于提高效率
    }
    FeetInches FeetInches::operator + (const FeetInches &right ) 
    { 
    FeetInches temp; 
    temp.inches = this->inches + right.inches;
    temp.feet = feet + right.feet;
    return temp; 
    }
    ```

### 6.9 单目运算符重载
  * 单目算术运算符有 ++、--、!、~（按位取反）等

    例如：对++运算符进行重载
     ```cpp
    class FeetInches 
    { 
      int feet, inches;
    public:
      FeetInches operator++( );//前置++ 
      FeetInches operator++(int);//后置++，其中int为哑元，用作区别标记
    }
    //前置++ 重载
    FeetInches FeetInches::operator++( )
    {
      ++inches; 
      return *this; 
    }
    // 后置++ 重载
    FeetInches FeetInches::operator++(int)
    { 
      FeetInches temp(feet, inches); //先把当前对象的值留下，赋给temp，然后对当前对象进行操作，返回的是当前对象修改之前的数据。
      ++inches;
      return temp;
    }
    ```

  ### 6.10 关系运算符重载
  * 关系算术运算符有 >、<、<=、>=、==、!= 等

    重载关系运算符，实现两个对象的比较，其中关系运算符函数要返回一个布尔值（true或false）:

    例如：对>运算符进行重载
    ```cpp
    class FeetInches 
    { 
      int feet, inches;
    public:
      bool operator> (const FeetInches & );
    }
    bool FeetInches::operator > (const FeetInches &right ) 
    { 
      if (feet > right.feet) 
        return true; 
      else if (feet==right.feet && inches> right.inches) 
        return true; 
      else 
        return false; 
    }
    ```
  ### 6.11 流操作符重载
  * 流操作符有 >>、<< 等

    由于cout本身不支持类对象的处理，如果要让它同样能打印类对象，必须得重载操作符<<。

    注意：如果要为FeetInches类重载流插入符<<，那么必须通过友元函数的形式实现函数重载。因为cout是一个标准的输出流对象，不是类中的对象，不能重载为类中的成员函数。

    例如：对<<进行重载如下
    ```cpp
    class FeetInches 
    { 
      int feet, inches;
    public:
      friend ostream &operator<<( ostream &,FeetInches &);
    }
    ostream &operator<<(ostream &strm, FeetInches &obj)
    { 
      strm << obj.feet << "feet, " << obj.inches <<" inches"; 
      return strm; 
    }
    ```
    distance1和distance2分别为FeetInches的两个对象：
    ```cpp
    cout << distance1 <<" "<< distance2 << endl ;
    ```
    等价于如下过程：

    （1）首先调用重载函数<<，执行cout << distance1，返回cout对象；

    （2）执行cout << “ ”，返回值是cout对象； 

    （3）以（1）的方式，执行cout << distance2；

    （4）以（2）的方式，执行表达式中的cout << endl；

  ### 6.12 类型转换运算符重载
  * 类型转换运算符()
  
    对于一个对象，通过重载类型转换函数，可实现类型转换功能。

    例如：对<<进行重载如下
    ```cpp
    class FeetInches 
    { 
      int feet, inches;
    public:
      operator float( );//函数无返回值类型
      operator int( ) { return feet; }
    }
    FeetInches::operator float( )
    { 
      float temp = feet; 
      temp += (inches / 12.0f); return temp; 
    }
    ```
    应用如下：
    ```cpp
    void main( ) 
    { 
      FeetInches  distance(3, 6);
      int  i;
      float  f;

      f = distance;            //	 f = distance.operator  float( );
      cout << f << endl;
      i = distance;             //   i = distance.operator  int( );
      cout << i << endl;
    }
    ```
    注意：对象到整形、浮点型的类型转换没有返回值
    
   ### <span id="613">6.13 下标运算符[]重载</span>
  
  * 下标操作符 [ ] 通常用于访问数组元素。重载该运算符用于增强操作 C++ 数组的功能。

    例如：
    ```cpp
    string name = "John"; 
    cout << name[0]; //代表的是值 
    name[0]='a'; //代表的是空间
    ```
    下面的实例演示如何重载下标运算符 [ ]：
    ```cpp
    class IntArray
    {
      int* aptr;
      int arraySize;
    public:
      IntArray(int s)
      {
          arraySize = s;
          aptr = new int[s];
          for (int i = 0; i < arraySize; i++)
              *(aptr + i) = 0;//让每一个值都为0
      }
      ~IntArray() { delete[] aptr; }
      int& operator[ ](const int& sub)//第一个&可以作为空间又可以作为数值，既可以放在赋值运算符的左边又可以放在右边
      {
          return aptr[sub]; //返回一个单元，必须返回一个引用
      }
    };
    void main()
    {
      IntArray table(10);
      int x;
      for (x = 0; x < 10; x++)
          table[x] = table[x] + 5;//前一个table[]指的是空间，后一个指的是值
      for (x = 0; x < 10; x++)
          cout << table[x] << " ";
      cout << endl;
      cout << "store a value in table[11].\n";
      table[11] = 0;
    }
    ```
### 注意：运算符重载不能改变运算符原来要求的参数个数。

---

## <span id="7">7 类的继承、多态、虚函数</span>
### 7.1 继承

  * 继承易于扩充现有类以满足新的应用。将已有的类称之为父类，也称基类；将新产生的类称为子类，也称为导出类或派生类。

    导出类不做任何改变地继承了基类中的所有变量和函数（构造函数和析构函数除外），并且还可以增加新的数据成员和函数，从而使导出类比基类更为特殊化。
    ```cpp
    class Grade 
    { 
      char letter; 
      float score; 
    public: 
      void setScore(float s); 
    };
    ```
    Test 子类公有继承 Grade父类
    ```cpp
    class Test : public Grade
    { 
      int numQuestions; 
    public: 
      Test( int, int );
    };
    ```
    父类中的公有成员在子类中仍是公有的，它们可以和子类中的公有成员一样被访问。但反过来是错误的，基类对象或基类中的某个函数不能调用子类中的函数。
### 7.2 保护成员和类的访问
  * 基类中的保护成员和私有成员比较类似，唯一的区别是：子类不可访问基类中的私有成员，但可访问基类中的保护成员。

    在公有继承或保护继承的情况下，子类能访问基类的protected成员。

    不同继承方式，基类成员在子类中的表现：
    |继承方式|基类成员在子类中的表现|
    |:-:|:-|
    |private|1．基类的私有成员在子类中不可访问；<br>2．基类的保护成员变成了子类中的私有成员；<br>3．基类的公有成员变成了子类中的私有成员。|
    |protected|1．基类的私有成员在子类中不可访问；<br>2．基类的保护成员变成了子类中的保护成员；<br>3．基类的公有成员变成了子类中的保护成员。|
    |public|1．基类的私有成员在子类中不可访问；<br>2．基类的保护成员变成了子类中的保护成员；<br>3．基类的公有成员变成了子类中的公有成员。|
    
    实例化表现：
    |基类成员在基类中的表现|继承方式|基类成员在子类中的表现|
    |:-|:-:|:-|
    |private: x<br>protected: y<br>public: z|private继承|x is inaccessible<br>private: y<br>private: z| 
    |private: x<br>protected: y<br>public: z|protected继承|x is inaccessible<br>protected: y<br>protected: z| 
    |private: x<br>protected: y<br>public: z|public继承|x is inaccessible<br>protected: y<br>public: z| 

  * 注意：

    （1）如果省略了继承修饰符，那么就是私有继承，如下：
    ```cpp
    class Test : Grade
    ```
    （2）不要将继承修饰符与成员的访问修饰符相混淆：

      * 继承修饰符是为了限定父类成员在子类中的表现 
      * 成员访问修饰符是规定类外语句能否访问类中的成员
### 7.3 保护成员和类的访问
   * 继承下的构造函数和析构函数
    
     当基类和子类都有构造函数时，如果定义一个子类对象，那么首先要调用基类的构造函数，然后再调用子类的构造函数；

     析构函数的调用次序与此相反，即先调用子类的析构函数，然后再调用基类的析构函数。

     例子：
     ```cpp
      class BaseDemo 
      { 
      public: 
        BaseDemo( ) { cout << "In BaseDemo constructor.\n"; }
        ~BaseDemo( ) { cout << "In BaseDemo destructor.\n"; } 
      };
      class DerivedDemo : public BaseDemo 
      { 
        public:
        DerivedDemo( ){ cout << "In DerivedDemo constructor.\n"; } 
        ~DerivedDemo( )
        { cout << "In DerivedDemo destructor.\n"; } 
      };
     ```
   * 向父类的构造函数传参数

      如果基类和子类都有缺省的构造函数，它们的调用是自动完成的，这是一种隐式调用。

      如果基类的构造函数带有参数，那么必须让子类的构造函数显式调用基类的构造函数，并且向基类构造函数传递适当的参数。
    
      实例：
      ```cpp
      class Rectangle 
      { 
      protected: 
        float width , length, area; 
      public: 
        Rectangle( ) { width = length = area = 0.0f ; } 
        Rectangle ( float w, float l ) 
        { 
          width = w; 
          length = l; 
          area = width * length; 
        } 
      };
      //子类Cube公有继承基类Rectangle
      class Cube : public Rectangle 
      { 
      protected: 
        float height, volume; 
      public: 
        Cube(float, float, float); 
      };
      //初始化列表
      Cube::Cube(float w, float l, float h) : Rectangle(w, l) 
      { 
        height = h ; 
        volume = area * height ; 
      }
      ```
### 7.4 初始化列表的作用
  * 初始化列表的作用 

    如果类之间具有继承关系，子类必须在其初始化列表中调用基类的构造函数。如：
    ```cpp
    class Base 
    { 
      Base( int x );
    }; 
    class Derived : public Base 
    { 
      Derived(int x, int y): Base(x) 
      { /* … */ } 
    };
    ```
  * 类中的const常量只能在初始化列表中进行初始化，而不能在函数内用赋值的方式初始化。如：
    ```cpp
    class Base 
    { 
      const int SIZE ; 
      Base(int size) : SIZE(size) 
      { /* … */ }
    }; 

    Base one(100);
    ```

  * 对象类型的成员的初始化放在初始化列表中，则效率较高，反之较低。基本类型变量的初始化可以在初始化列表中，也可在构造函数中，效率上没区别。如：
    ```cpp
    class Base
    { 
      Base( ); 
      Base(const Base &other); 
    }；
    class Derived
    {
      Base B_Member;
    public: Derived(const Base &a); 
    };
    ```

    构造函数的实现：
    ```cpp
    Derived::Derived(const Base & b ) :B_Member(b)
    { /* … */ }
    ```
    也可这样实现，但效率较低：
    ```cpp
    Derived::Derived(const Base &b) 
    { B_Member = b; }
    ```
### 7.5 覆盖基类的函数成员
  
  * 覆盖与重载的区别

      重载的特点：
    
      * 重载表现为有多个函数，它们的 名字相同，但参数不全相同；

      * 重载可以出现在同一个类中，也可出现在具有继承关系的父类与子类中；

      * 重载也可表现为外部函数的形式。
      
        例如：
        ```cpp
        class Base
        {
        public: 
          int fun(int x) 
          {
            cout<<x<<”n”;
          } 
        }；
        class Derived: public Base 
        {
        public: 
          int fun(int x,int y) 
          {
            cout<<x+y<<”\n”<<endl;
          } 
        };
        ```
      覆盖的特点：
      * 覆盖一定出现在具有继承关系的基类和子类之间； 

      * 覆盖除了要求函数名完全相同，还要求相应的参数个数和类型也完全相同； 
      
      * 当进行函数调用时，子类对象所调用 的是子类中定义的函数； 
      
      * 覆盖是C++多态性的部分体现。
        ```cpp
        class Base
        { 
        public: 
          int fun(int x) 
          {
            cout<<x<<”n”;
          } 
        }；
        class Derived: public Base 
        { 
        public: 
          int fun(int x) 
          {
            cout<<x+y<<”\n”;
          } 
        };
        ```
### 7.6 虚函数与纯虚函数
* 虚函数

  函数覆盖体现了一定的多态性。但是，简单的函数覆盖并不能称为真正的多态性。

  不支持多态性的语言不是一个正在的OOP语言。

  错误实例：
  ```cpp 
  class MileDist
  {
  protected:
      float miles;
  public:
      void setDist(float d) { miles = d; }
      float getDist() { return miles; }
      float square()
      {
          return getDist() * getDist();//谁的？
      }
  };
  class FeetDist : public MileDist 
  { 
  protected: 
      float feet; 
  public: 
      void setDist(float); 
      float getDist() { return feet; }
      float getMiles() { return miles; } 
  }; 
  void FeetDist::setDist(float ft)
  { 
      feet = ft; 
      MileDist::setDist(feet / 5280); 
  }
  void main() 
  { 
      FeetDist feet; 
      float ft; 
      cout << "请输入以英尺为单位的距离：";
      cin >> ft; 
      feet.setDist(ft); 
      cout << feet.getDist() << " 英尺等于 "; 
      cout << feet.getMiles() << " 英里\n"; 
      cout << feet.getDist() << " 平方等于 "; 
      cout << feet.square() << " \n"; 
  }
  ```
  错误的原因：
  C++编译器在缺省情况下，对函数成员的调用实施的是静态连编（也称静态绑定）。

  注意：父类中调用函数是提前确定的，没有根据当前对象类型确定。

  OOP: 覆盖和重载不能体现真正的多态性，只有虚函数才是多态性的表现。不支持多态 性的语言，就不能称为OOP。
  ```cpp
  class MileDist 
  { 
  protected: 
      float miles; 
  public: 
      void setDist(float d) { miles = d; } 
      virtual float getDist() { return miles; }
      float square() { return getDist() * getDist(); } 
  };
  ```
* 纯虚函数

  纯虚函数是在基类中声明的虚函数，没有函数体，要求继承基类的子类必须覆盖它。 
   
  带有纯虚函数的类称为抽象类，不能定义抽象类的对象。
  
  派生类可以根据自己的需要，分别覆盖纯虚函数，从而实现真正意义上的多态性。 
  
  格式如下:
  ```cpp
  virtual void showInfo( ) = 0;
  ```
  实例：
  ```cpp
  class Student 
  {
  protected: 
    char name[51]; 
    int hours;
  public: 
    Student() { name[0] = hours = 0; } 
    void setName(char* n) { strcpy(name, n); } 
    // Pure virtual function
    virtual void setHours( ) = 0; 
    virtual void showInfo( ) = 0;
  };
  class CsStudent : public Student 
  { 
    int mathHours, csHours;
  public: 
    void setMathHours(int mh) { mathHours = mh; } 
    void setCsHours(int csh) { csHours = csh; } 
    void setHours() 
    { hours = mathHours + csHours;  } 
    void showInfo(); 
  };
  void CsStudent::showInfo() 
  { 
    cout << " Name: " << name << endl; 
    cout << "\t Math: " << mathHours << endl;
    cout << "\t CS : " << csHours;
    cout << "\n\t Total Hours: " << hours; 
  } 
  void main() 
  {
    CsStudent student1; 
    char chInput[51]; 
    int intInput;
    cout << "Enter the following information:\n"; 
    cout << "Name: "; 
    cin.getline(chInput, 51); 
    student1.setName(chInput);
    cout << "Number of math hours completed: "; 
    cin >> intInput; 
    student1.setMathHours(intInput); 
    cout << "Number of CS hours completed: "; 
    cin >> intInput; 
    student1.setCsHours(intInput); 
    student1.setHours(); 
    cout << "\nSTUDENT INFORMATION\n"; 
    student1.showInfo(); 
  }
  ```
* 关于抽象类和纯虚函数小结
    
  如果一个类包含有纯虚函数，那么它就是抽象类，必须让其它类继承；
    
  基类中的纯虚函数没有代码； 
    
  不能定义抽象类的对象，即抽象基类不能实例化；
    
  必须在子类中覆盖基类中的纯虚函数。

* 指向父类的指针

  指向基类对象的指针可以指向其子类的对象； 
  
  如果子类覆盖了基类中的成员，但通过基类指针所访问的成员仍是基类的成员，而不是子类成员。

  实例：
  ```cpp
  class Base
  { 
  public: 
    void show() { cout << "In Base class.\n"; } 
  }; 
  class Derived : public Base 
  { 
  public: 
    void show() { cout << "In Derived class.\n"; } 
  }; 
  void main() 
  { 
    Base* bptr; 
    Derived dobject; 
    bptr = &dobject; 
    bptr->show();
  }
  ```

### 7.7 多重继承与多继承
* 多重继承
  
  类C继承类B中所有的成员，包括B从A中继承所得的成员

  如：class C->class B->class A
* 多继承

  如果一个子类具有两个或多个直接父类，那么就称为多继承。

  对父类构造函数的调用，是按照继承的顺序进行。

  实例：
  ```cpp
  class DateTime : public Date, public Time{}
  ```  

### 7.8 类模板
  * 类模板用于创建类属类和抽象数据类型，从而使程序员可以创建一般形式的类，而不必编写处理不同数据类型的类。

    类模板的定义和实现必须在同一个文件中，通常是头文件。编译器看到模 板实现时才展开模板。

	  实例：
	  ```cpp
	  template  < class  T >
	  class  FreewillArray 
	  {
	  public:
	      FreewillArray( ) {  aptr = 0 ;  arraySize = 0 ;}
	      FreewillArray( int ) ;	// 构造函数
	      FreewillArray( const FreewillArray  & ) ;  // 拷贝构造函数
	      ~FreewillArray( ) ;    	// 析构函数
	      int  size( )  {  return  arraySize ;  }
	      T  &operator[ ]( const  int  & ) ; 	// 对 [ ] 进行重载
	  private:
	      T  	*aptr ;			// 采用模板参数T替换过去的int 
	      int  	arraySize ;
	      void  memError( ) ;    // 处理内存分配错误
	      void  subError( ) ;    // 处理下标越界错误
	  } ;

		//  FreewillArray类模板的构造函数。设置数组的大小，并对数组分配内存
	  template  < class  T >
	  FreewillArray  < T >::FreewillArray( int  s ) 
	  {
	      arraySize = s ;
	      aptr = new T [s] ;
	      if( aptr == 0 )    
	      memError( ) ;
	      for( int  count = 0 ;  count < arraySize ;  count++ ) 
	      *( aptr + count ) = 0 ;
	  }

	      //  FreewillArray类模板的拷贝构造函数。
	  template  < class  T >
	  FreewillArray  < T >::FreewillArray( const FreewillArray  &obj ) 
	  {
	      arraySize = obj.arraySize ;
	      aptr = new T [arraySize] ;
	      if( aptr == 0 )    
	      memError( ) ;
	      for( int  count = 0 ;  count < arraySize ;  count++ ) 
	      *( aptr + count ) = *( obj.aptr + count ) ;
	  }

	      //  FreewillArray类模板的析构函数。
	  template  < class  T >
	  FreewillArray  < T >::~FreewillArray( ) 
	  {
	      if( arraySize > 0 ) 
	      delete [ ] aptr ;
	  }

	      //  memError 函数。当内存分配出错时，显示错误信息，并终止程序
	  template  < class  T >
	  void  FreewillArray  < T >::memError( ) 
	  {
	      cout << "错误：无足够的内存空间.\n" ;
	      exit( 0 ) ;
	  }

	      //  subError 函数成员。当数组下标越界时，显示错误信息，并终止程序
	  template  < class  T >
	  void  FreewillArray  < T >::subError( ) 
	  {
	      cout << "错误：数组下标越界\n" ;
	      exit( 0 ) ;
	  }

	      //  重载运算符[ ]，函数的参数是一个下标，在正常情况下，函数返回
	      // 下标指定的数组元素的引用，否则调用subError函数终止程序。
	  template  < class  T >
	  T  &FreewillArray  < T >::operator[ ]( const  int  &sub ) 
	  {
	      if( sub < 0 || sub > arraySize )
	      subError( ) ;
	      return  aptr[sub] ;
	  }
	  int  main( ) 
	  {   
	      FreewillArray <int> intTable(10);    //intTable和floatTable都是对象
	      FreewillArray <float> floatTable(10) ;
	    int x;

	      for( x = 0 ;  x < 10 ;  x++ ) 	    // 在数组中存储值
	      {
	      intTable[x] = x ;
	      floatTable[x] = x ;
	      }

	      // 显示数组中的值
	      cout << "intTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << intTable[x] << "  " ;
	      cout << endl ;

	      cout << "floatTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << floatTable[x] << "  " ;
	      cout << endl ;

	      // 对数组元素采用内嵌+操作
	      for( x = 0 ;  x < 10 ;  x++ ) 	
	      {
	      intTable[x] = intTable[x] + 1 ;
	      floatTable[x] = floatTable[x] + 1.5f ;
	      }

	      // 显示数组中的值
	      cout << "intTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << intTable[x] << "  " ;
	      cout << endl ;

	      cout << "floatTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << floatTable[x] << "  " ;
	      cout << endl ;

	      // 对数组元素采用内嵌++操作
	      for( x = 0 ;  x < 10 ;  x++ ) 	
	      {
	      intTable[x]++ ;
	      floatTable[x]++ ;
	      }

	      // 显示数组中的值
	      cout << "intTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << intTable[x] << "  " ;
	      cout << endl ;

	      cout << "floatTable中的值是：\n\t" ;
	      for( x = 0 ;  x < 10 ;  x++ ) 
	      cout << floatTable[x] << "  " ;
	      cout << endl ;

	      return 0;
	  }
	  ``` 

---

## <span id="8">8 异常处理</span>

* 基本异常

  异常是在程序执行期间的突发性事件

  异常与错误不同，错误可以通过编译系统处理

* 抛出异常
  ```cpp
  float divide(int number, int div) {
    if(div == 0) {
      throw "ERROR: divided by zero";
    }
    else {
      return float(number) / div;
    }
  }
  ```

* 处理异常
  ```cpp
  try {
    <可能出现异常的代码>
  }
  catch (exception param1) {
    <处理异常类型1的代码>
  }
  catch (exception param2) {
    <处理异常类型2的代码>
  }
  ```

* 异常处理失败的原因

  try语句块中世纪产生的异常，与catch语句圆括号指定要捕捉的异常类型不匹配

  try语句的范围太小，在try语句之前就已经产生了异常，那么后面的try语句块将不再执行

* 基于对象的异常处理

  C++除了支持基本类型的异常处理外，还支持面向对象的异常处理

  C++在处理多种类型的异常时，要求这些异常对象必须属于不同类型，并且对于每种类型的异常都要编写一段对应的catch代码

  栗子：
  ```cpp
  class IntRange {
    int input, lowest, highest;
  public:
    class tooLow {};
    class tooHigh {};
    InRange() {
      lowest = lowest;
      highest = highest;
    }
    int getInput() {
      cin >> input;
      if(input < lowest) {
        throw tooLow();
      }
      else if(input > highest) {
        throw tooHigh();
      }
      return input;
    }
  };
  int main() {
    InRange range;
    int uerValue;
    try {
      userValue = range.getInput();
    } 
    catch(IntRange::tooLow) {...}
    catch(IntRange::tooHigh) {...}
    return 0;
  }
  ```

  还可以通过异常对象将异常信息传递给异常处理者
  ```cpp
  class IntRange2 {
    int input;
  public:
    class OutOfRange {
    public: 
      int value;
      OutOfRange(int i) {
        value = i;
      }     
    };
    int getInput() {
      cin>>input;
      if(...) {
        throw OutOfRange(input);
      }
      return iuput;
    }
  };
  int main() {
    IntRange2 range;
    int userValue;
    try {
      userValue = range.getInput();
    }
    catch (IntRange2::OutOfRange ex) {
      cout << ex.value;
    }
    return 0;
  }
  ```

* 注意事项
  
  * 一旦程序抛出异常，即使在异常处理以后，程序也不能回到原来的抛出点继续执行

  * 一旦程序抛出异常，执行throw语句的函数将立即停止运行
  * 对象的函数成员抛出了异常，那么将立即对该对象调用析构函数
  * 在try块中创建了对象，并且这些对象还未来得及析构，那么将对这些对象立即调用析构函数

* 再次抛出异常

  ```cpp
  try {
    ...
  }
  catch(exception param1) {
    ...
    throw; //经过处理后再次抛出异常交给函数调用链的上层函数处理
  }
  catch(exception param2) {
    ...
  }
  ```


---

## <span id="9">9 标准模板STL</span>

### 9.1 STL 概述

* 标准模板库：常用数据结构和算法的模板的集合

* 容器：可以容纳各种数据类型的通用数据结构，是类模板

* 迭代器：可以用于依次存取容器中的元素，类似于指针

* 算法：用来操作容器中的元素的函数模板

### 9.2 容器

* 顺序容器

  * vector

    动态数组。元素在内存连续存放，随机储存任何元素都能在常数时间完成
  
  * deque

    双向队列，元素在内训连续存放，随机存取任何元素都能在常数时间完成（次于vector）
  
  * list

    双向链表，元素在内存不能连续存放，在任何位置增删元素都能在常数时间完成，不支持随机存取

  * array

  * forward_list （C++ 11中介绍）

* 关联容器

  * 元素是排序的，插入任何元素，都应按相应的排列规则来确定位置，因此具有较好的性能

  * 通常以平衡二叉树的方式实现，插入于检索的时间都是O(log(N))

  * set/multiset
  
    set就是集合，set中不允许相同的元素，multiset中则允许存在相同的元素
  
  * map/multimap
  
    map与set的不同之处在于map中存放的元素有且仅有两个，第一个是first，另一个是second，并且根据first的值来进行排序和检索，multimap中则允许相同的first元素

  * 在关联容器前加上 unordered_ 则是非排序（C++ 11中介绍）

* 容器适配器

  * stack

    栈，是项的有限序列，并且满足序列中被删除、检索和修改的项只是最近插入序列的项，后进先出
  
  * queue

    队列，插入只可以在尾部进行，删除、检索和修改只允许从头部进行，先进先出
  
  * priority_queue

    优先队列，最高优先级元素总是第一个出列

### 9.3 迭代器

* 用于指向顺序容器和关联容器中的元素，用法和指针类似

* 有const和非const两种，通过非const还能修改其指向的元素

* 通过迭代其可以读取它指向的元素

* 迭代器示例
  ```cpp
  int main() {
    vector<int> v;
    v.push_back(1);

    vector<int>::const_iterator i;
    for(i = v.begin(); i != v.end(); ++i) {
      cout<<*i<<",";
    }
    cout<<endl;
    return 0;
  }
  ```

* 双向迭代器

  若p和p1都是双向迭代器，则可对p、p1进行如下操作

  |||
  |:-:|:-|
  |++p, p++|使p指向容器中的下一个元素|
  |--p, p--|使p指向容器中的上一个元素|
  |*p|取p指向的元素|
  |p = p1|赋值|
  |p == p1, p != p1|判断是否相等、不等|

* 随机访问迭代器

  若p和p1都是随机访问迭代器，则可对p、p1进行以下操作

  |||
  |:-:|:-|
  |p += i|将p向后移动i个元素|
  |p -= i|将p向前移动i个元素|
  |p + i|指向p后面的第i个元素的迭代器|
  |p - i|指向p前面的第i个元素的迭代器|
  |p[i]|p后面第i个元素的引用|
  |p < p1, p <= p1...|比较大小|
  |p - p1|返回p与p1之间的元素个数|

* 小总结
  |容器|容器上的迭代器类别|
  |:-:|:-:|
  |vector|随机访问|
  |deque|随机访问|
  |list|双向访问|
  |set/multiset|双向访问|
  |map/multimap|双向访问|
  |stack|不支持迭代器|
  |queue|不支持迭代器|
  |priority_queue|不支持迭代器|

  注意

  * 有的算法例如sort、binary_search需要通过随机访问迭代器来访问容器中的元素

  * 双向迭代器不支持 < ，list里面也没有 [ ] 成员函数

  * 随机访问迭代器可以通过 v[i] 来访问成员

### 9.4 算法

* 两个重要算法

  * sort 排序

    ```cpp
    sort(startaddress, endaddress)

    startaddress: the address of the first element of the array

    endaddress: the address of the next contiguous location of the last element of the array.

    So actually sort() sorts in the range of [startaddress,endaddress)
    ```

  * binary_search
  
    主要思想是将数组一分为二（分而治之），直到找到元素，或者所有元素都用完为止。
    ```cpp
    binary_search(startaddress, 
              endaddress, valuetofind)
    Parameters :
    startaddress: the address of the first 
                  element of the array.
    endaddress: the address of the next contiguous 
                location of the last element of the array.
    valuetofind: the target value which we have 
                 to search for.
    Returns :
    true if an element equal to valuetofind is found, else false.
    ```

* 顺序容器和关联容器中皆有的函数成员
  
  |函数名|含义|
  |:-:|:-|
  |begin|返回指向容器中第一个元素的迭代器|
  |end|返回指向容器中最后一个元素后面位置的迭代器|
  |rbegin|返回指向容器中最后一个元素的迭代器|
  |rend|返回指向容器中第一个元素前面的位置的迭代器|
  |insert|向容器中插入某个（些）元素|
  |find|查找等于某个值的元素|
  |erase|从容器中删除一个或者几个元素|
  |clear|从容器中删除所有元素|

* 顺序容器的常用成员函数

  |函数名|含义|
  |:-:|:-|
  |front|返回容器中第一个元素的引用|
  |back|返回容器中最后一个元素的引用|
  |push_back|在容器末尾增加新的元素|
  |pop_back|删除容器末尾的元素|
  |erase|删除迭代器指向的元素（可能会使其失效），或者删除一个区间，返回被删除元素后面的元素的迭代器|

  注意：List除了顺序容器的所有成员函数以外还支持以下8种函数：

  |函数名|含义|
  |:-:|:-|
  |push_front|在前面插入|
  |pop_front|删除前面的元素|
  |sort|排序，list 不支持 STL 的排序|
  |remove|删除和指定值相等的所有元素|
  |unique|删除所有和前一个元素相同的元素|
  |merge|合并两个列表，并且清空被合并的辣个|
  |reverse|颠倒列表|
  |splice|在指定位置插入另一个链表的一个或多个元素，并在另一个链表中删除被插入的元素|

* 关联容器的常用成员函数

  |函数名称|含义|
  |:-:|:-|
  |upper_bound|查找上界|
  |lower_bound|查找下界|
  |equal_range|同时查找上下界|
  |count|计算等于某个值的元素个数|

#### 更多内容参考：https://www.geeksforgeeks.org/algorithms-library-c-stl/


















  
