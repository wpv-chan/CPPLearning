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

