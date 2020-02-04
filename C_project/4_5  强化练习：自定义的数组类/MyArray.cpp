//
//  MyArray.cpp
//  4_5  强化练习：自定义的数组类
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "MyArray.hpp"


MyArray::MyArray(){
    cout << "MyArray()..." << endl;
    this->len = 0;
    this->space = nullptr;
}

MyArray::MyArray(int len){
    cout << "MyArray(int len)..." << endl;
    if (len <= 0) {
        return;
    }
    else{
        this->len = len;
        this->space = new int[this->len];           // space开辟空间
    }
}

MyArray::MyArray(const MyArray &another){
    cout << "MyArray(const MyArray &another)..." << endl;
    if (another.len > 0) {
        this->len = another.len;
        // 深拷贝
        this->space = new int[this->len];
        for (int i = 0; i < this->len; i++) {
            this->space[i] = another.space[i];
        }
    }
}

MyArray::~MyArray(){
    cout << "~MyArray()..." << endl;
    if (this->space != nullptr) {
        delete[] this->space;
        this->space = nullptr;
        this->len = 0;
    }
}

void MyArray::setData(int index, int data){
    if (this->space != nullptr) {
        this->space[index] = data;
    }
}

int MyArray::getData(int index){
    return this->space[index];
}

int MyArray::getLength(){
    return this->len;
}
