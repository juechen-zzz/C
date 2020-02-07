//
//  MyString.hpp
//  5_5  强化练习：自定义的字符串类（多文件）
//
//  Created by 倪浩鹏 on 2020/2/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>
using namespace std;

class MyString{
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &another);
    ~MyString();
    
    char &operator[](int index);
    bool operator==(const MyString &another);
    MyString & operator=(const MyString &another);
    MyString operator+(const MyString &another);

    friend ostream & operator<<(ostream &os, MyString &s);
    friend istream & operator>>(istream & is, MyString &s);
private:
    int len;
    char *str;
};

#endif /* MyString_hpp */
