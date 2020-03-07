//
//  Employee.hpp
//  5_2  强化练习：multimap案例
//
//  Created by 倪浩鹏 on 2020/3/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
using namespace std;

class Employee{
public:
    Employee();
    Employee(string name);
    Employee(string name, int age, long long number, int salary);
    void PrintInformation();
private:
    string name;
    int age;
    long long number;
    int salary;
};

#endif /* Employee_hpp */
