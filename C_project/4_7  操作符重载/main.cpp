//
//  main.cpp
//  4_7  操作符重载
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
重载规则：
    只能对已有的C++运算符重载，不能自定义运算符，至少有一个自定义数据类型
    有四种不允许重载（成员选择符. 成员对象选择符.* 域解析操作符:: 条件操作符?:）
    重载不能改变运算符运算对象个数
    重载不改变优先级、结合性
    重载不能够有默认参数
*/

#include <iostream>
using namespace std;

class Complex{
public:
    Complex(int a, int b){
        this->a = a;
        this->b = b;
    }
    void printT(){
        cout << "(" << this->a << " + " << this->b << "i)" << endl;
    }
    // friend Complex operator+(Complex &c1, Complex &c2);
    // friend Complex & operator+=(Complex &c1, Complex &c2);
    
    // 法二：操作符重载写在成员函数
    Complex operator+(Complex &another){
        Complex tmp(this->a + another.a, this->b + another.b);
        return tmp;
    }
    Complex & operator+=(Complex &another){
        this->a += another.a;
        this->b += another.b;
        return *this;
    }
private:
    int a;
    int b;
};

/*
// 法一：操作符重载写在全局
Complex operator+(Complex &c1, Complex &c2){
    Complex tmp(c1.a + c2.a, c1.b + c2.b);
    return tmp;
}

Complex & operator+=(Complex &c1, Complex &c2){
    c1.a += c2.a;
    c1.b += c2.b;
    return c1;
}
*/

int main(int argc, const char * argv[]) {
    Complex c1(1, 2);
    Complex c2(2, 4);
    c1.printT();
    c2.printT();
    
    Complex c3 = c1 + c2;   // Complex c3 = operator+(c1, c2); 等价写法(全局)
                            // Complex c3 = c1.operator+(c2);  等价写法(局部)
    c3.printT();
    
    c1 += c2;
    c1.printT();
    return 0;
}


/*
 特殊案例：重载++
        void & operator++(Complex &c)           重载的是前++
        void & operator++(Complex &c, int)      重载的是后++
 */
