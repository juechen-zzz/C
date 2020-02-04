//
//  MyArray.hpp
//  4_5  强化练习：自定义的数组类
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <iostream>
using namespace std;

class MyArray{
public:
    MyArray();
    MyArray(int len);
    MyArray(const MyArray &another);
    ~MyArray();
    
    void setData(int index, int data);
    int getData(int index);
    int getLength();
    
private:
    int len;
    int *space;     // 指向堆上的空间
};

#endif /* MyArray_hpp */
