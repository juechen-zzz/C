//
//  main.cpp
//  5_2  强化练习：multimap案例
//
//  Created by 倪浩鹏 on 2020/3/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    公司今天招聘了5个员工，5名员工进入公司后，需要指定员工在哪个部门工作
    人员信息：姓名 年龄 电话 工资
    通过multimap进行信息的插入、保存和显示
    分部门显示员工信息，显示全部员工信息
 */

#include <iostream>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Employee.hpp"
using namespace std;

#define SALE_DEAPRTMENT 1
#define DEVELOPMENT_DEPARTMENT 2
#define FINACIAL_DEPARTMENT 3
#define ALL_DEPARTMENT 4


void CreateEmployee(vector<Employee> &v){
    string NameList = "abcde";
    for (int i = 0; i < 5; i++) {
        string s = "Employee_";
        s += NameList[i];
        Employee e(s, (rand() % 10 + 20), rand(), 10000 + (rand() % 10000));
        v.push_back(e);
    }
}

void DivideEmployee(vector<Employee> &v, multimap<int, Employee> &m){
    srand(time(nullptr));           // 增加随机种子，这样是真的每次都随机生成
    for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++) {
        int departID = rand() % 3 + 1;
        switch (departID) {
            case 1:
                m.insert(make_pair(1, (*it)));
                break;
            case 2:
                m.insert(make_pair(2, (*it)));
                break;
            case 3:
                m.insert(make_pair(3, (*it)));
                break;
            default:
                break;
        }
    }
}

void PrintEmployee(multimap<int, Employee> &m, int departID){
    // count(keyElem) 返回容器中key = keyElem的对组个数
    multimap<int, Employee>::iterator it = m.find(departID);
    int num = (int)m.count(departID);
    int n = 0;
    for (multimap<int, Employee>::iterator pos = it; it != m.end() && n < num; pos++, n++) {
        (*pos).second.PrintInformation();
    }
}



int main(int argc, const char * argv[]) {
    vector<Employee> v;
    multimap<int, Employee> m;
     
    CreateEmployee(v);
    DivideEmployee(v, m);
    cout << "------------SALE_DEAPRTMENT-----------" << endl;
    PrintEmployee(m, SALE_DEAPRTMENT);
    cout << "--------DEVELOPMENT_DEPARTMENT--------" << endl;
    PrintEmployee(m, DEVELOPMENT_DEPARTMENT);
    cout << "---------FINACIAL_DEPARTMENT----------" << endl;
    PrintEmployee(m, FINACIAL_DEPARTMENT);
    return 0;
}
