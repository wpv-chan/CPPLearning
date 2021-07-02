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
  strncpy(dst,. src);
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

---

## <span id="3">3 结构体与列表</span>

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

---

## <span id="9">9 标准模板STL</span>

