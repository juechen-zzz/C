//
//  main.cpp
//  3_2  拷贝构造函数
//
//  Created by 倪浩鹏 on 2020/2/1.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 当没有任何的显式构造函数（显式无参，有参，**显式拷贝构造**）时，默认的构造函数会出现
// 当没有显式的拷贝构造函数，默认的拷贝构造函数会出现
// 当没有显式的析构函数，默认的析构函数会出现

class Test{
public:
    Test(int x, int y){
        m_x = x;
        m_y = y;
    }
    
    Test(){
        m_x = 0;
        m_y = 0;
    }
    
    Test(const Test &another){
        m_x = another.m_x;
        m_y = another.m_y;
    }
    
    void printT(){
        cout << "x = " << m_x << "  y = " << m_y << endl;
    }
    
private:
    int m_x;
    int m_y;
};


int main(int argc, const char * argv[]) {
    Test t1(100, 200);
    t1.printT();
    
    // 用t1的值来给t2赋值，拷贝构造函数
    Test t2(t1);        // Test t2 = t1 等价写法
    t2.printT();
    return 0;
}
