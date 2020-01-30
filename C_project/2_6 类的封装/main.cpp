//
//  main.cpp
//  2_6 类的封装
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

struct Date {
    int year;
    int mouth;
    int day;
};

void init_date(struct Date &d){
    cout << "------year:mouth:day------" << endl;
    cin >> d.year;
    cin >> d.mouth;
    cin >> d.day;
}

void print_date(struct Date &d){
    cout << d.year << "年" << d.mouth << "月" << d.day << "日";
}

bool is_leap_year(struct Date &d){
    if (((d.year % 4 == 0) && (d.year % 100 != 0)) || (d.year % 400 == 0)) {
        return true;
    }
    return false;
}


class My_date{ // 类中默认的访问权限是private
public:
    void init_date(){
        cout << "------year:mouth:day------" << endl;
        cin >> year;
        cin >> mouth;
        cin >> day;
    }
    
    void print_date(){
        cout << year << "年" << mouth << "月" << day << "日";
    }
    
    bool is_leap_year(){
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return true;
        }
        return false;
    }

protected:      //在单个类中和private功能一样，在继承时会有区别
    
private:
    int year;
    int mouth;
    int day;
    
};

int main(int argc, const char * argv[]) {
    Date d1;
    init_date(d1);
    print_date(d1);
    if (is_leap_year(d1)) {
        cout << ",是闰年" << endl;
    }
    else{
        cout << ",不是闰年" << endl;
    }
    
    
    // 用类的方式实现
    My_date d2;
    d2.init_date();
    d2.print_date();
    if (d2.is_leap_year()) {
        cout << ",是闰年" << endl;
    }
    else{
        cout << ",不是闰年" << endl;
    }
    return 0;
}
