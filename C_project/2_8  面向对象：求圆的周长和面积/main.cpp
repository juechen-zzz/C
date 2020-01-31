//
//  main.cpp
//  2_8 面向对象：求圆的周长和面积
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 面向过程
double get_circle(double r){
    return 2 * 3.14 * r;
}

double get_area(double r){
    return 3.14 * r * r;
}

// 面向对象
class Circle{
public:
    void init_r(double r){
        m_r = r;
    }
    
    double get_circle(){
        return 2 * 3.14 * m_r;
    }

    double get_area(){
        return 3.14 * m_r * m_r;
    }
    
private:
    double m_r;
    // double m_circle = 2 * 3.14 * m_r;    这是错误写法，此时m_r还没有初始化，会代入一个乱码m_r
};


int main(int argc, const char * argv[]) {
    double r = 10;
    cout << "周长为：" << get_circle(r) << endl;
    cout << "面积是：" << get_area(r) << endl;
    
    Circle f;
    f.init_r(r);
    cout << "周长为：" << f.get_circle() << endl;
    cout << "面积是：" << f.get_area() << endl;
    return 0;
}
