//ex14_1_3
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date myDate;
    int year;
    int month;
    int day;

    try{
        cout<<"Pls input YYYY: "<<endl;
        cin>>year;
        cout<<"Pls input MM: "<<endl;
        cin>>month;
        cout<<"Pls input DD: "<<endl;
        cin>>day;
        myDate.setDate(month, day, year);
    }

    catch(Date::InvalidMonth){
        cout<<"Wrong Month"<<endl;
    }
    catch(Date::InvalidDay){
        cout<<"Wrong Day"<<endl;
    }
}