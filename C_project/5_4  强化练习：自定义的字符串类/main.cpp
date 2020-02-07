//
//  main.cpp
//  5_4  强化练习：自定义的字符串类
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
#include <string>
using namespace std;

class Test{
public:
    Test(int a, char *name){
        this->a = a;
        this->name = name;
//        double len = strlen(name);
//        this->name = new char(len + 1);
    }
private:
    int a;
    string name;
//    char *name;
};



int main(int argc, const char * argv[]) {
    string s1 = "123";
    string s2 = "124";
    cout << s1 + s2 << endl;
    
    s2[1] = 'X';
    cout << s1 + s2 << endl;
    return 0;
}
