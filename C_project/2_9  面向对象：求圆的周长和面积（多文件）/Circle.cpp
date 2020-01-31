//
//  Circle.cpp
//  2_9 面向对象：求圆的周长和面积（多文件）
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "Circle.hpp"

// 注意作用域
void Circle::init_r(double r){
    m_r = r;
}


double Circle::get_circle(){
    return 2 * 3.14 * m_r;
}


double Circle::get_area(){
    return 3.14 * m_r * m_r;
}
