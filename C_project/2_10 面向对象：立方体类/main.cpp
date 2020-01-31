//
//  main.cpp
//  2_10 面向对象：立方体类
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 设计一个Cube类，表示一个立方体，能求体积，并且用全局函数和成员函数分别判断两个立方体是否相同

#include <iostream>
#include "Cube.hpp"
using namespace std;

// 判断是否为同一个立方体
bool is_the_same(class Cube &p1, class Cube &p2){
    if ((p1.get_length() - p2.get_length() == 0) &&
        (p1.get_width() - p2.get_width() == 0) &&
        (p1.get_height() - p2.get_height() == 0)
        )
    {
        return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    Cube f1;
    f1.init_c();
    cout << "f1体积为：" << f1.get_v() << endl;
    
    Cube f2;
    f2.init_c();
    cout << "f2体积为：" << f2.get_v() << endl;
    
    cout << "-----------------------" << endl;
    
    cout << is_the_same(f1, f2) << endl;
    cout << f2.is_the_same(f1) << endl;
    return 0;
}
