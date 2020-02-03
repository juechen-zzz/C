//
//  goods.cpp
//  4_2  强化练习：仓库货物管理(多文件)
//
//  Created by 倪浩鹏 on 2020/2/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "goods.hpp"

Goods::Goods(){
    m_weight = 0;
    next = nullptr;
    cout << "创建了一个重量为" << m_weight << "kg的货物" << endl;
}

Goods::Goods(int weight){
    m_weight = weight;
    next = nullptr;
    m_total_weight += m_weight;
    cout << "创建了一个重量为" << m_weight << "kg的货物" << endl;
}

Goods::~Goods(){
    cout << "删除了一个重量为" << m_weight << "kg的货物" << endl;
    m_total_weight -= m_weight;
}

int Goods::m_total_weight = 0;

int Goods::get_m_total_weight(){
    return m_total_weight;
}
