# C++ 期末复习整理 20210701

## 目录

1. [字符串与指针](#1)
   
2. [指针与函数](#2)
3. [结构体与列表](#3)
4. [文件操作](#4)
5. [类的基础部分](#5)
6. [类的高级部分](#6)
7. [类的继承、多态、虚函数](#7)
8. [异常处理](#8)
9. [标准模板STL](#9)
    
---

## <span id="1">1 字符串与指针</span>

### 1.1 处理字符与字符串

* 求字符串的长度
  <pre name = "code" class = "c++">
  char name[10] = {'T', 'o', 'm', '\0', 'P', 'e', 't', 'e', 'r', '\0'};
  cout << strlen(name) << sizeof(name) << endl; 
  </pre>
  注意：求字符串长度时，到'\0'就会结束

* 字符串的拷贝
  
  **方式一**
  <pre name = "code" class = "c++">
  char* strcpy(char s1[], char s2[])
  </pre>
  例如
  <pre name = "code' class = "c++">
  char src[80] = {"I am a student"};
  char dst[80];
  strcpy(dst,. src);
  </pre>
  注意：不能使用‘=’号进行直接赋值

  **方式二**
  <pre name = "code" class = "c++">
  char* strncoy(char s1[], const char s2[], int len)
  </pre>
  例如
  <pre name = "code" class = "c++">
  char src[80] = {"I am a student"};
  char dst[80];
  strncpy(dst, src);
  dst[10] = '\0';
  </pre>
  注意：必须加上'\0'字符串结束标志

* 字符串的连接
  <pre name = "code" class = "c++">
  char* strcat(char s1[], const char s2[], int len)
  </pre>
  将s2字符串连接到s1的尾部，修改了s1，返回的是s1的首地址

  注意：s1的空间要足够大
  
  例如：
  <pre name = "code" class = "c++">
  char s1[20] = "You";
  char s2[20] = "&Me";
  strcat(s1, s2);
  </pre>

* 字符串的比较
  
  **方式一**
  <pre name = "code" class = "c++">
  int strcmp(const char s1[], const char s2[])
  </pre>
  比较两个字符串的大小，就是从左到右逐个比较对应字符的ASCII码

  若s1 > s2，则返回1

  若s1 < s2，则返回-1

  若s1 = s2，则返回0

  **方式二**
  <pre name = "code" class = "c++">
  int strncmp(const char s1[], const s2[], int len)
  </pre>
  比较两个字符串的前len个字符，若字符串s1或者s2的长度小于len，则与strcmp无异

  例如：
  <pre name = "code" class = "c++">
  char s1[10] = "China";
  char s2[10] = "Chinese";
  cout << strncmp(s1, s2, 5) << endl;//输出结果为-1
  </pre>

* 字符串的大小写转换
  
  **大写变小写**
  <pre name = "code" class = "c++">
  char* strlwr(char s[])
  </pre>
  **小写变大写**
  <pre name = "code" class = "c++">
  char* strupr(char s[])
  </pre>

* 字符串的子串查找
  <pre name = "code" class = "c++">
  char* strstr(const char s1[], const char s2[])
  </pre>
  如果字符串s1包含要查找的子串s2，则返回s1在s1中第一次出现的地址，否则直接返回NULL

* 字符串转换为整数的函数
  <pre name = "code" class = "c++">
  int atoi(const char str[])
  </pre>
  例如：
  <pre name = "code" class = "c++">
  char s1[80] = "789123",
  s2[80] = "789X123",
  s3[80] = "X123";
  int i = atoi(s1);//789123
  int j = atoi(s2);//789
  int k = atoi(s3);//0
  </pre>
  转换成别的数据类型就自己类比啦

  atof，atod...

* 整数转换为字符串
  <pre name = "code" class = "c++">
  char* itoa(int value, char str[], int radix)
  </pre>
  例如：
  <pre name = "code" class = "c++">
  int n = 123;
  char s1[20], s2[20];
  itoa(n, s1, 3);//处理3进制
  itoa(n, s2, 10);//处理10进制
  </pre>

### 1.2 标准C++的String类

* 包含的头文件
  <pre name = "code" class = "c++">
  string
  </pre>

* 读取整行
  <pre name = "code" class = "c++">
  string name;
  getline(cin, name);
  </pre>
  注意：要和char类型做区分
  <pre name = "code" class = "c++">
  char name[10];
  gets(name);
  cin.get(name, 10);
  cin.getline(name, 10);
  </pre>

* string对象的比较
  string对象也可以与字符串比较，例如
  <pre name = "code" class = "c++">
  string name1 = "John";
  char name2[10] = "Jone";
  cout << (name1 > name2);//0
  cout << (name1 < name2);//1
  cout << (name1 == name2);//0
  </pre>

* string对象的初始化
  <pre name = "code" class = "c++">
  string test1;    //空串
  string test2 = "内容"; //使用=
  string test3("内容");   //使用引用字符数组作为参数传给构造函数
  string test4(test2); //用一个string初始化另一而string
  string test5(test2,pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
  string test6 = test2 + "内容" + test3 //混合初始化
  string test7 = test2.substr(pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
  string test8 = test2.substr(); //参数列表为空则会拷贝test2的整个对象（复制test2的简便方法）
  string test9(num,ch); //拷贝num个字符型ch到test9
  </pre>

* string类型常用的操作符
  <pre name = "code" class = "c++">
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
  </pre>

### 1.3 指针的概念、指针变量的定义和使用

* 指针变量就是存放地址的变量
  
* 定义指针变量
  例如：
  <pre name = "code" class = "c++">
  int* pInt;
  </pre>
  注意：
   
    * 指针不知向内存的0号单元，若指针变量值为0或者NULL，则表示空指针
  
    * 地址值与整型数值不同

    * 无论何种类型的指针都占用4个字节的内存空间
  

* 运算符*与&
  
  *：通过指针访问所指变量的数值

  &：访问指针内储存的地址

* 引用指针变量
  <pre name = "code" class = "c++">
  int x = 30, y = 90;
  int *p1 = &x, *p2 = &y, t;
  t = *p1;
  *p1 = *p2;
  *p2 = t;
  </pre>
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
  <pre name = "code" class = "c++">
  int a[10], *p;
  p = a;
  p = &a[0];//二者等价
  </pre>

* 指针比较

  指向同一个数组的两个指针可以进行比较

  逆序存放的代码
  <pre name = "code" class = "c++">
  for(p1 = set, p2 = set+length-1; p1 < p2; p1++, p2--) {
    t = *p1;
    *p1 = *p2;
    *p2 = t;
  }
  </pre>

* 指针变量之间的加法无意义

* 指向二维数组元素的指针
  
  二维数组元素a[i][j]的表示
  <pre name = "code" class = "c++">
  //表示地址
  &a[i][j]
  a[i]+j
  *(a+i)+j
  
  //表示数值
  a[i][j]
  \*(a[i]+j)
  \*(\*(a+i)+j)
  (\*(a+i))[j]
  </pre>
  注意：a[0] == a[0][0]

  一个通用的二维数组的输出例子
  <pre name = "code" class = "c++">
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
  </pre>

---

## <span id="2">2 指针与函数</span>

### 2.1 参数的传递方式

* 基本类型的变量作函数形参
  
  交换变量x与y的值，采用基本类型的变量做函数形参
  <pre name = "code" class = "c++">
  void swap(int a, int b) {
    int t;
    t = a;
    a = b;
    b = t;
  }
  </pre>
  这是单向的值传递，形参的变化不会影响实参

* 引用类型作为函数形参

  交换变量x与y的值，采用引用类型做函数的形参
  <pre name = "code" class = "c++">
  void swap(int& a, int& b) {
    int t;
    t = a;
    a = b;
    b = t;
  }
  </pre>
  通过定义被调用中的参数为引用类型，将主调函数的值改变

* 指针类型作为函数形参

  交换变量x与y的值，采用指针类型做函数形参
  <pre name = "code" class = "c++">
  void swap(int* px, int* py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
  }
  </pre>
  通过定义被调用函数中的参数为指针类型，通过间接存取将主调函数的值改变

  注意：指针类型做参数形参的另一种形式是数组名做函数参数

### 2.2 返回指针的函数及指向函数的指针

* 指针型函数
  
  一个函数的返回值是某种数据类型的地址值就是指针型函数
  <pre name = "code" class = "c++">
  int* function(int x, int y) {
    return x+y;
  }
  </pre>

* 函数指针
  
  函数的入口地址。函数指针变量就是指向函数入口地址的变量。
  <pre name = "code" class = "c++">
  int (*fun)(int , int);
  int max(int x, int y) {
    return x > y?x : y;
  }
  fun = max;
  </pre>
  用法示例
  <pre name = "code" class = "c++">
  int process(int x, int y, int (*fun)(int, int)) {
    return fun(x, y);
  }
  </pre>

### 2.3 指针数组与指向指针的指针

* 指针数组
  
  一个数组里面所有的元素都是指针变量称为指针数组

* 指针数组与数组指针的本质区别就是*与[]的优先级顺序不同

  <pre name = "code" class = "c++">
  int (*p)[M]; //p是一个数组指针，一个行指针，指向拥有M个元素的一维数组
  int* p[M]; //p是一个指针数组，包含有M个指针
  </pre>

* main函数的参数
  
  在main()函数头部声明的格式为
  <pre name = "code" class = "c++">
  int main(int argc, char* argv[])
  int main(int argc, char** argv)
  //argc表示命令行中字符串的个数
  //argv[]指向命令行中的各个字符串
  </pre>
  举个栗子，通过命令行参数计算输入数据的和
  <pre name = "code" class = "c++">
  int main(int argc, char* argv[]) {
    int sum, i;
    cout << "Command name:" << argv[0] << endl;
    for(sum = 0, i = 1; i < argc; i++) {
      sum += atoi(argv[i]);
    }
    cout << "Sum is:" << sum << endl;
  }
  </pre>

* 指向指针的指针
  
  举个栗子
  <pre name = "code" class = "c++">
  int x, *p = &x, **pp = p;
  </pre>

### 2.4 内存的动态分配与释放

* 变量存储空间的分配是系统完成的，不需用户干预
  
  * 静态变量：编译时分配空间
  
  * 动态变量：系统运动时分配空间

* 程序动态申请空间是由用户在编程时安排的
* 申请多少空间由运行时情况而定，一般通过指针访问空间
* new用于动态申请储存空间，delete用于释放new申请的存储空间
  <pre name = "code" class "c++">
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
  </pre>
  注意：如果函数的参数是一个指针，不要用指针去申请动态内存，否则会因为申请的空间无法释放而造成内存泄漏

### 2.5 void 和 const 修饰指针变量

#### 2.5.1 void修饰指针变量

* void修饰指针
  
  void修饰指针代表是一种不确定类型的指针

* 任何类型的指针都可以直接赋给它，无需类型转换

  <pre name = "code" class = "c++">
  void* p1;
  int* p2;
  p1 = p2;
  </pre>

* 不能对void指针进行算数操作

#### 2.5.2 const修饰指针变量
  
* 指向常量的指针
  
  可以改变指针所指的空间，但不可以通过指针改变现在所指的内容

  <pre name = "code" class = "c++">
  int i = 6;
  const int* p1 = &i;
  const int m = 16;
  *p1 = 16; //wrong
  p1 = &m; //true
  </pre>

* 常量指针

  可以改变指针所指向空间中的内容，但是不能改变指针的指向

  <pre name = "code" class = "c++">
  char stringA[10] = "abcd", stringB[10] = "xyz";
  char* const sp = atringA;
  sp = stringB; //wrong
  *(sp+1) = 't'; //true
  </pre>

* 指向常量的指针常量

  既不可以修改指针所指的内容又不可改变指针的指向

---

## <span id="3">3 结构体与列表</span>

### 3.1 结构体的建立

* 结构体就是通过定义一种数据类型，把不同的数据作为一个整体来处理

* 结构体是一种由程序员创建的抽象数据类型

* 先定义结构体
  <pre name = "code" class = "c++">
  struct<结构体名称> {
    <成员列表>
  }; //这里不要忘记了;号
  </pre>

* 再定义变量
  <pre name = "code" class = "c++">
  student John, Mary;
  struct student John, Mary;
  </pre>

* 也可以使用无结构体名构造一次性结构体
  <pre name = "code" class = "c++">
  struct {
    int ID;
    char name[10];
  }John, Mary;
  </pre>

* 初始化结构体类型的变量

  用{}括起来的值对结构体变量进行初始化，例如
    <pre name = "code" class = "c++">
    student John = {666, "Joe"};
    </pre>

  用同类型的结构体变量初始化另外一个结构体变量
    <pre name = "code" class = "c++">
    student Merry = John;
    </pre>

* 结构体类型变量及其成员的引用

  引用结构体变量的成员
  <pre name = "code" class = "c++">
  John.ID = 2333;
  </pre>

  整体引用结构体变量
  <pre name = "code" class = "c++">
  student John = {...};
  student Merry;
  Merry = John;
  </pre>

  注意

  * 不能将结构体作为一个整体进行输入或者输出

  * 结构体变量可以用作函数的参数，属于按值传递

  * 函数可以返回一个结构体变量

### 3.2 结构体的应用

* 使用结构体变量作为函数参数的效率较低，因为结构体作为形参需要赋值

* 结构体数组与指针

  定义结构体数组和初始化
  <pre name = "code" class = "c++">
  student studentList[4];
  student studentList[4] = {{...}, {...}, {...}, {...}};
  </pre>

  使用结构体数组
  <pre name = "code" class = "c++">
  //引用元素
  for(int i = 0; i < 4; i++) {
    cout << studentList[i].name;
  }
  //指针
  student *ps;
  ps = stud;
  ps++;
  </pre>

### 3.3 typedef 定义类型名

* 语法格式
  <pre name = "code" class = "c++">
  tyoedef <原类型名> <自定义的类型名>
  </pre>

  栗子：
  <pre name = "code" class = "c++">
  typedef char NAME[100];
  NAME Joe;
  //等价于下面
  char Joe[100];
  </pre>

* 注意typedef与#define的不同

  * 关键字typedef在编译阶段有效，具有类型检查的功能

  * #define是宏定义，发生在预处理阶段，只会进行简单的字符替换，不做任何检查

  * #define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用

  * typedef则具有自己的作用域

* 用typedef定义新类型名
  
  * typedef只能用于为已知数据类型名定义新的类型名，并没有增加新的数据类型

  * typedef用于软件移植
  
    比如定义一个叫REAL的浮点类型，在目标平台一上，让它表示最高精度的类型为
    <pre name = "code" class = "c++">
    typedef long double REAL;
    </pre>

    而在不支持long double的第二平台上，改为
    <pre name = "code" class = "c++">
    typedef double REAL;
    </pre>

    在连double都不支持的平台上，改为
    <pre name = "code" class = "c++">
    typedef float REAL;
    </pre>

### 3.4 链表

* 链表的引入

  * 数据空间是连续的
  
  * 实际应用无法确定数组的大小
  * 定义足够大————空间浪费

* 链表的结构
  <pre name = "code" class = "c++">
  struct student {
    int ID;
    char name[20];
    student* next; //链表与结构体的区别
  };
  </pre>

* 单向链表
  
  带有头节点的单向链表

  不带头节点的单向链表

* 链表的应用示例
  <pre name = "code" class = "c++">
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
  </pre>

---

## <span id="4">4 文件操作</span>

---

## <span id="5">5 类的基础部分</span>

---

## <span id="6">6 类的高级部分</span>

---

## <span id="7">7 类的继承、多态、虚函数</span>

---

## <span id="8">8 异常处理</span>

* 基本异常

  异常是在程序执行期间的突发性事件

  异常与错误不同，错误可以通过编译系统处理

* 抛出异常
  <pre name = "code" class = "c++">
  float divide(int number, int div) {
    if(div == 0) {
      throw "ERROR: divided by zero";
    }
    else {
      return float(number) / div;
    }
  }
  </pre>

* 处理异常
  <pre name = "code" class = "c++">
  try {
    <可能出现异常的代码>
  }
  catch (exception param1) {
    <处理异常类型1的代码>
  }
  catch (exception param2) {
    <处理异常类型2的代码>
  }
  </pre>

* 异常处理失败的原因

  try语句块中世纪产生的异常，与catch语句圆括号指定要捕捉的异常类型不匹配

  try语句的范围太小，在try语句之前就已经产生了异常，那么后面的try语句块将不再执行

* 基于对象的异常处理

  C++除了支持基本类型的异常处理外，还支持面向对象的异常处理

  C++在处理多种类型的异常时，要求这些异常对象必须属于不同类型，并且对于每种类型的异常都要编写一段对应的catch代码

  栗子：
  <pre name = "code" class = "c++">
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
  </pre>

  还可以通过异常对象将异常信息传递给异常处理者
  <pre name = "code" class = "c++">
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
  </pre>

* 注意事项
  
  * 一旦程序抛出异常，即使在异常处理以后，程序也不能回到原来的抛出点继续执行

  * 一旦程序抛出异常，执行throw语句的函数将立即停止运行
  * 对象的函数成员抛出了异常，那么将立即对该对象调用析构函数
  * 在try块中创建了对象，并且这些对象还未来得及析构，那么将对这些对象立即调用析构函数

* 再次抛出异常
  <pre name = "code" class = "c++">
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
  </pre>

---

## <span id="9">9 标准模板STL</span>

