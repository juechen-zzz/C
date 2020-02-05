//
//  main.cpp
//  4_8  左移右移操作符重载
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;


class Complex{
    friend ostream & operator<<(ostream &os, Complex &c);
    friend istream & operator>>(istream &is, Complex &c);
public:
    Complex(int a, int b){
        this->a = a;
        this->b = b;
    }
private:
    int a;
    int b;
};


// 左移操作符重载，只能写成全局函数，写成成员函数调用顺序会变反
ostream & operator<<(ostream &os, Complex &c){
    os << "(" << c.a << " + " << c.b << "i)";
    return os;
}

// 右移操作符重载
istream & operator>>(istream &is, Complex &c){
    cout << "输入a和b:";
    is >> c.a;
    is >> c.b;
    return is;
}

int main(int argc, const char * argv[]) {
    Complex c1(1, 2);
    cout << c1 << endl;
    
    cin >> c1;
    cout << c1 << endl;
    return 0;
}
