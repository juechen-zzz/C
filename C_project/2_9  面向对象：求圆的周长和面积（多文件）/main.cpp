//
//  main.cpp
//  2_9 面向对象：求圆的周长和面积（多文件）
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// C++标准双文件形式，一个类对应一个.cpp和一个.h头文件
// .h中写类的声明 .cpp中写类的实现

#include <iostream>
#include "Circle.hpp"
using namespace std; 

int main(int argc, const char * argv[]) {
    Circle f;
    double r = 10;
    f.init_r(r);
    cout << "周长为：" << f.get_circle() << endl;
    cout << "面积是：" << f.get_area() << endl;
    return 0;
}
