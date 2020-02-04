//
//  goods.hpp
//  4_2  强化练习：仓库货物管理(多文件)
//
//  Created by 倪浩鹏 on 2020/2/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


// 静态成员变量和成员函数的初始化必须在类外，也不要写在头文件中

#ifndef goods_hpp
#define goods_hpp

#include <iostream>
using namespace std;

class Goods{
public:
    // 构造函数
    Goods();
    Goods(int weight);
    
    // 定义指针
    Goods *next;
    
    ~Goods();
    static int get_m_total_weight();
    
private:
    int m_weight;
    static int m_total_weight;
};

#endif /* goods_hpp */
