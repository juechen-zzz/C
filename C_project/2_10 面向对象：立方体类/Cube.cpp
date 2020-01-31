//
//  Cube.cpp
//  2_10 面向对象：立方体类
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "Cube.hpp"
using namespace std;

void Cube::init_c(){
    cout << "-----------------------" << endl;
    cin >> m_length;
    cin >> m_width;
    cin >> m_height;
}

double Cube::get_length(){
    return m_length;
}

double Cube::get_width(){
    return m_width;
}

double Cube::get_height(){
    return m_height;
}

double Cube::get_v(){
    return m_length * m_width * m_height;
}

bool Cube::is_the_same(class Cube &p){
    // 此处的get_length可以替换为p.m_length,因为此时还在类的内部，同类之间无私处
    if ((p.get_length() - m_length == 0) &&
        (p.get_width() - m_width == 0) &&
        (p.get_height() - m_height == 0)
        )
    {
        return true;
    }
    return false;
}
