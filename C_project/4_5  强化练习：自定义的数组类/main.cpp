//
//  main.cpp
//  4_5  强化练习：自定义的数组类
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 数组类封装：解决实际问题，训练构造函数、copy构造函数等，为操作符重载作准备

#include <iostream>
#include "MyArray.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
    MyArray array1(10);
    
    for (int i = 0; i < 10; i++) {
        array1.setData(i, i+10);
    }
    
    cout << "--------------------------" << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << array1.getData(i) << " ";
    }
    cout << endl;
    
    cout << "--------------------------" << endl;
    
    MyArray array2 = array1;
    
    for (int i = 0; i < 10; i++) {
        cout << array2.getData(i) << " ";
    }
    cout << endl;
    return 0;
}
