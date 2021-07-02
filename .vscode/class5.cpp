#include <bits/stdc++.h>
using namespace std;

//指针
//运算符&是取地址，*是取值（通过指针来间接访问所指变量

//指针与函数

//函数参数的传递方式
//  传值调用
//  传引用

void swap(int *x, int *y);//数组的话可以不加*号，只要确保输入的是地址即可
int main_fun1() {
    int x, y;
    swap(&x, &y);//如果是数组则可以不添加&符号
    return 0;
}

//返回指针的函数以及指向函数的指针
//  返回指针的函数

int* fun(int x, int y);

float *search(float (*p)[4], int n) {
    return *(p+n);
}
int main_fun2() {
    float score[][4] = { { 60,70,80,70 },{ 67,78,89,98 },{ 78,88,89,98 } };
	float *p;
	int i, m;
	cin >> m;//输入学号
	p = search(score, m);
	for (i = 0; i<4; i++) cout << setw(5) << *(p + i);
    return 0;
}

//  函数指针（这样函数就能作为参数用在别的函数里面）

int (*Pfun)(int ,int);//注意小括号不能漏掉

int max(int, int);
int min(int, int);
int add(int, int);
int process(int x, int y, int(*fun)(int, int)) {
	return fun(x, y);
}
int main_fun3() {
	int a, b;
	cin >> a >> b;
	cout << process(a, b, max) << endl;
	cout << process(a, b, min) << endl;
	cout << process(a, b, add) << endl;
	//system("pause");
	return 0;
}
int max(int x, int y) {
	return (x > y ? x : y);
}
int min(int x, int y) {
	return (x <y ? x : y);
}
int add(int x, int y) {
	return (x+y);
}

//指针数组和指向指针的指针

//指针数组

void sort(char *color[], int n);
void output(char *color[], int n);
void sort(char *color[], int n)
{
	char *ptr;
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(color[k], color[j]) > 0) k = j;
		}
		if (k != i)
		{
			ptr = color[i]; color[i] = color[k]; color[k] = ptr;
		}
	}
}
void output(char *color[], int n)
{
	int i;
	//输出 color[i]
	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::setw(10) << color[i];
	}
	std::cout << std::endl;
	//输出 (int)color[i] 就是个地址
	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::setw(10) << (int)color[i];
	}
	std::cout << std::endl;
	//输出 *color[i]和 *(color[i] + 1)
	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::setw(10) << *color[i] << "," << *(color[i] + 1);
	}
	std::cout << std::endl;
}

int main_fun4()
{
	//char colorchar[] = "test";
	//std::cout << colorchar << std::endl;

	//int colorint[5] = { 1, 2, 3, 4, 5 };
	//std::cout << *colorint << std::endl;

	//char*pa = "def";
	//std::cout << (int)pa << std::endl;

	char *color[] = { "Yellow", "Blue", "Red", "Green", "Orange" };
	sort(color, 5);
	output(color, 5);
	system("pause");
	return 0;
}

//main函数的参数

int main(int argc, char *argv[]) {
	int sum, i;
	cout << "Command name:" << argv[0] << endl;
	for (sum = 0, i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}
	cout << "Sum is :" << sum << endl;
	return 0;
}

//指向指针的指针

int *p[10];
int **pp = p;

//内存的动态分配和释放

//new：动态申请储存空间
//delete：释放new

int *iptr;
iptr = new int;
*iptr = 25;
delete iptr;