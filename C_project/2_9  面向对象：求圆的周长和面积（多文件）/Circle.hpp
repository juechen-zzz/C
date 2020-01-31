//
//  Circle.hpp
//  2_9 面向对象：求圆的周长和面积（多文件）
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 防止头文件被重复引用
#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>


class Circle{
public:
    // 只需要写函数名声明，设置半径
    void init_r(double r);
    // 周长
    double get_circle();
    // 面积
    double get_area();
    
private:
    double m_r;
};


#endif /* Circle_hpp */
