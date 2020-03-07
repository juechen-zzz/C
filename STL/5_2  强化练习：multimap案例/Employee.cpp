//
//  Employee.cpp
//  5_2  强化练习：multimap案例
//
//  Created by 倪浩鹏 on 2020/3/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "Employee.hpp"

Employee::Employee(){
    
}

Employee::Employee(string name){
    this->name = name;
    this->age = 0;
    this->number = 0;
    this->salary = 0;
}

Employee::Employee(string name, int age, long long number, int salary){
    this->name = name;
    this->age = age;
    this->number = number;
    this->salary = salary;
}

void Employee::PrintInformation(){
    cout << this->name << ": " << this->age << "-" << this->number << "-" << this->salary << endl;
}
