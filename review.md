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
  string name("LiSA");
  string singer(name);
  
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

