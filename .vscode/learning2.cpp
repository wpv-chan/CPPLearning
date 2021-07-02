//ex15_1_2
#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int main() {
    int array_1[6] = {10, 15, 2, 8, 22, 11};
    int array_2[8] = {1, 5, 10, 22, 4, 8, 33, 6};
    list<int> list_1;
    list<int> list_2;
    for(int i = 0; i < 6; i++) {
        list_1.push_back(array_1[i]);
    }
    for(int i = 0; i < 8; i++) {
        list_2.push_back(array_2[i]);
    }

    list<int>::iterator i;
    cout<<"The first list: ";
    for(i = list_1.begin(); i != list_1.end(); i++) {
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"The second list: ";
    for(i = list_2.begin(); i != list_2.end(); i++) {
        cout<<*i<<" ";
    }
    cout<<endl;

    list_1.splice(list_1.end(), list_2);
    cout<<"List after splice operation: ";
    for(i = list_1.begin(); i != list_1.end(); i++) {
        cout<<*i<<" ";
    }
    cout<<endl;

    list_1.sort();
    list_1.unique();

    cout<<"Final list: ";
    for(i = list_1.begin(); i != list_1.end(); i++) {
        cout<<*i<<" ";
    }
    return 0;
}