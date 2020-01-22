//
//  test.cpp
//  C++增强部分
//
//  Created by 倪浩鹏 on 2020/1/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "test.hpp"
#include <iostream>
using namespace std;

void test5(){
    int a = 10;
    // 引用数据类型，前面有数据类型则为引用，否则为取地址
    int &re = a;
    re = 50;
    cout << "re = " << re << endl;
    
    // void my_swap(int *a, int *b)
    // void my_swap2(int &a, int &b)
}



