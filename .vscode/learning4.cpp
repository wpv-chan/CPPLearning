//ex11_1_1
#include <bits/stdc++.h>
//#include <iostream>
//#include <string.h>
using namespace std;

class Person {
    char name[20];
    int age;
    static int counter;
public:
    Person() {
        memset(name, '\0', strlen(name));
        age = 0;
    }
    Person(char* name, int age) {
        strcpy(this -> name, name);
        this -> age = age;
        counter++;
    }
    //~Person();
    
    static int ShowCounter() {
        return counter;
    }
    void ShowName() {
        for(int i = 0; i < strlen(name); i++) {
            cout<<name[i];
        }
        cout<<endl;
    }
    void ShowAge() {
        cout<<age<<endl;
    }
};

int Person::counter = 0;

int main() {
    char name[20] = {'\0'};
    int age = 0;
    Person person[10];
    int index = 0;
    while(1) {
        cout<<"Whether to continue typing? Yes(enter 1)/No(enter 0)"<<endl;
        cin>>age;
        if(age == 0) {
            break;
        }
        cout<<"Pls input name"<<endl;
        cin>>name;
        //cin.getline(name, 20);
        cout<<"Pls input age"<<endl;
        cin>>age;

        Person temp(name, age);
        person[index++] = temp;
    }

    cout<<"There are "<<person[0].ShowCounter()<<" in total"<<endl;

    for(int i = 0; i < person[i].ShowCounter(); i++) {
        cout<<"The "<<i+1<<" person's Name is ";
        person[i].ShowName();
        cout<<"The "<<i+1<<" person's Age is ";
        person[i].ShowAge();
    }
    return 0;
}