#include <bits/stdc++.h>
using namespace std;

//处理字符串的函数（常用）

char name[10] = {'T', 'o', 'm', '\0', 'P', 'e', 't', 'e', 'r', '\0'};
cout<<strlen(name);
cout<<sizeof(name);

//字符串的拷贝
char *strcpy(char, const char);
char *strncpy(char, const char, int);//记得拷贝完在末尾加上\0

//字符串连接函数
char *strcat(char, const char, int);//若有返回值，则为第一个字符串

//字符串的大小比较
int *strcmp(const char, const char);//若两个相等则为0，左边大于右边返回1，反之则为-1
int *strncmp(const char, const char, int);

//大小写的转换
char *strlwr(char);//若大写转小写则用这个
char *strupr(char);//若小写转大写就用这个

//查找子串
char *strstr(const char, const char);//返回s2在s1中第一次出现的位置（地址）

//字符串转成整数
int atoi(const char);//若转换过程中有非数字字符阻隔，则只会转前面的数字
//整数转换成字符串
char *itoa(int , char, int radix);//最后面的这个进制类型直接阿拉伯数字即可

//读取整行
string name;
getline(cin, name);


