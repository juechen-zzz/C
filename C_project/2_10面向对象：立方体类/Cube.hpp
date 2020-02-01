//
//  Cube.hpp
//  2_10 面向对象：立方体类
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <iostream>

class Cube{
public:
    void init_c();
    double get_v();
    
    double get_length();
    double get_width();
    double get_height();
    bool is_the_same(class Cube &p);

private:
    double m_length;
    double m_width;
    double m_height;
};

#endif /* Cube_hpp */
