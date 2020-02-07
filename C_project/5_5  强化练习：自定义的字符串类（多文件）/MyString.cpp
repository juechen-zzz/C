//
//  MyString.cpp
//  5_5  强化练习：自定义的字符串类（多文件）
//
//  Created by 倪浩鹏 on 2020/2/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "MyString.hpp"

// 无参构造
MyString::MyString(){
    this->len = 0;
    this->str = nullptr;    // "\0" 和 nullptr 不等价
}

// 有参构造
MyString::MyString(const char *str){
    this->len = (int)strlen(str);
    if (str == nullptr) {
        this->len = 0;
        this->str = new char[0 + 1];
        strcpy(this->str, "");
    }
    else{
        int len = (int)strlen(str);
        this->len = len;
        this->str = new char[this->len + 1];
        strcpy(this->str, str);
    }
}

// 拷贝构造
MyString::MyString(const MyString &another){
    this->len = another.len;
    this->str = new char[this->len + 1];
    strcpy(this->str, another.str);
}

// 析构函数
MyString::~MyString(){
    if (this->str != nullptr) {
        cout << "执行了析构函数" << endl;
        delete[] this->str;
        this->str = nullptr;
        this->len = 0;
    }
}

// <<操作符重载
ostream & operator<<(ostream &os, MyString &s){
    os << s.str;
    return os;
}

// >>操作符重载
istream & operator>>(istream & is, MyString &s){
    // 将s之前的字符串释放
    if (s.str != nullptr) {
        delete[] s.str;
        s.str = nullptr;
        s.len = 0;
    }
    // 通过cin添加新的字符串
    char tmp_str[4096] = {0};
    cin >> tmp_str;
    s.len = (int)strlen(tmp_str);
    s.str = new char(s.len);
    strcpy(s.str, tmp_str);
    return is;
}

// []操作符重载
char & MyString::operator[](int index){
    return this->str[index];
}

// ==操作符重载
bool MyString::operator==(const MyString &another){
    if (this->len != another.len) {
        return false;
    }
    else {
        for (int i = 0; i < this->len; i++) {
            if (this->str[i] != another.str[i]) {
                return false;
            }
        }
    }
    return true;
}

// =操作符重载
MyString & MyString::operator=(const MyString &another){
    if (this == &another) {
        return *this;
    }
    if (this->str != nullptr) {
        this->len = 0;
        delete[] this->str;
        this->str = nullptr;
    }
    this->len = another.len;
    this->str = new char[this->len + 1];
    strcpy(this->str, another.str);
    return *this;
}

// +操作符重载
MyString MyString::operator+(const MyString &another){
    int len = this->len + another.len;
    MyString temp;
    temp.len = len;
    temp.str = new char[len + 1];
    // memset(temp.str, 0, len + 1);
    // strcat(temp.str, this->str);
    strcpy(temp.str, this->str);
    strcat(temp.str, another.str);
    return temp;
}
