//ex12_1_1
#include <bits/stdc++.h>
using namespace std;

class NumDays {
	float hours;
	float days;
	char* name;

public:
	NumDays() {
        hours = 0;
		days = 0;
	}
	NumDays(char* d, const float = 0);
	void setHours(const float);
	void setDays(const float);
	float getHours(void);
	float getDays(void);
	NumDays operator=(const NumDays &right); //同时对小时和天数，员工姓名赋值
	float operator+(NumDays &); //同时累加小时和天数
	float operator-(NumDays &); //小时和天数同时相减
	bool operator>(const NumDays &); //比较员工工作天数大小
	NumDays operator++(); //小时和天数同时++
	NumDays operator++(int); //小时和天数同时++
	NumDays operator--(); //小时和天数同时--
	NumDays operator--(int); //小时和天数同时--
	friend ostream &operator<<(ostream &, NumDays &); //小时、天数和员工姓名同时输出
	friend istream &operator>>(istream &, NumDays &); //小时、天数和员工姓名同时输入
	operator double(); //转换天数到double
};

ostream &operator<<(ostream &Output, NumDays &Object) {
	cout<<"Hours: ";
	Output<<Object.hours<<endl;
	cout<<"Days: ";
	Output<<Object.days<<endl;
	cout<<"Name: ";
	Output<<Object.name<<endl;
}

istream &operator>>(istream &Input, NumDays &Object) {
	cout<<"Name: ";
	Object.name = new char[10];
	Input>>Object.name;
	cout<<"Hours: ";
	Input>>Object.hours;
	cout<<"Days: ";
	Input>>Object.days;
	return Input;
}

NumDays::operator double() {
	double temp = days;
	return temp;
}

NumDays NumDays::operator--(int ) {
	NumDays temp;
	temp.hours = hours;
	temp.days = days;
	--hours;
	--days;
	return temp;
}

NumDays NumDays::operator--() {
	--hours;
	--days;
	return *this;
}

NumDays NumDays::operator++(int ) {
	NumDays temp;
	temp.hours = hours;
	temp.days = days;
	++hours;
	++days;
	return temp;
}

NumDays NumDays::operator++() {
	++days;
	++hours;
	return *this;
}

bool NumDays::operator>(const NumDays &right) {
	if(this -> days > right.days) {
		return true;
	}
	return false;
}

float NumDays::operator-(NumDays &right) {
	NumDays temp;
	temp.hours = this -> hours - right.hours;
	temp.days = this -> days - right.days;
	return temp;
}

float NumDays::operator+(NumDays &right) {
	NumDays temp;
	temp.hours = this -> hours + right.hours;
	temp.days = this -> days + right.days;
	return temp;
}

NumDays NumDays::operator=(const NumDays &right) {
	//delete []name;
	name = new char[strlen(right.name) + 1];
	strcpy(name, right.name);
	hours = right.hours;
	days = right.days;
}

void NumDays::setHours(float hours) {
	this -> hours = hours;
}

void NumDays::setDays(float days) {
	this -> days = days;
}

float NumDays::getHours() {
	return hours;
}

float NumDays::getDays() {
	return days;
}

int main() {
	NumDays numDays_1, numDays_2, temp;
	cin>>temp;
	numDays_1 = temp;

	cin>>temp;
	numDays_2 = temp;

	numDays_1.setDays(5);
	numDays_2.setHours(20);

	cout<<"Output"<<endl<<numDays_1<<endl<<numDays_2;
	return 0;
}