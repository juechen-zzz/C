//
//  main.cpp
//  3_3  拷贝构造函数的应用场景
//
//  Created by 倪浩鹏 on 2020/2/1.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;


class Test{
public:
    Test(){
        cout << "Test()..." << endl;
        m_x = 0;
        m_y = 0;
    }
    
    Test(int x, int y){
        cout << "Test(int x, int y)..." << endl;
        m_x = x;
        m_y = y;
    }
    
    Test(const Test &another){
        cout << "Test(const Test &another)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }
    
    // =操作符
    void operator=(const Test &another){
        cout << "operator=(const Test &another)..." << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }
    
    // 析构函数调用顺序，与构造函数相反，谁先构造，谁后析构
    ~Test(){
        cout << "~Test()..." << endl;
    }
    
    void printT(){
        cout << "x = " << m_x << "  y = " << m_y << endl;
    }
    
private:
    int m_x;
    int m_y;
};



int main(int argc, const char * argv[]) {
    Test t1(10, 20);
    Test t2(t1);
    Test t3;
    t3 = t1;
    return 0;
}
