//
//  main.cpp
//  5_5  强化练习：自定义的字符串类（多文件）
//
//  Created by 倪浩鹏 on 2020/2/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
   实现一个字符串类
       构造函数要求：MyString a;
                  MyString a("dddd");
                  MyString b = a;
       常用的操作符： <<  >>  !=  ==  >  <  =  []
*/

#include <iostream>
#include "MyString.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    MyString s1("abc");
    MyString s2(s1);
    cout << "s1为：" << s1 << endl;
    cout << "s2为：" << s2 << endl;
    cout << "s1[1]为：" << s1[1] << endl;
    
    MyString s3("1231");
    s3 = s1;
    cout << "s3为：" << s3 << endl;
    
    cout << "(s1 == s2)为：" << (s1 == s2) << endl;
    
    MyString s4("654321");          // 最先的析构函数是因为+中有一个temp
    cout << "输入s4的内容:";
    cin >> s4;
    cout << "s4为：" << s4 << endl;
    
    MyString s5;
    s5 = (s1 + s2);
    cout << "s5为：" << s5 << endl;
    return 0;
}
