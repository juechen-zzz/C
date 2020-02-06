//
//  main.cpp
//  4_3  this指针
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 可以用this返回当前对象的地址，this指向调用该成员函数方法的对象地址（&t1）
// this指针不是const Test *，是一个Test *const(常指针，指针不可修改，指向的区域内容可以修改)


class Test{
public:
    Test(int a){
        this->m_a = a;
    }
    void getA() const   // 成员函数尾部出现const修饰的不是函数，修饰的是this指针，这样就是只读的，内容不可修改
    {
        cout << "a = " << m_a << endl;
        cout << "a = " << this->m_a << endl;
    }
private:
    int m_a;
};

/*
struct Test2{
    int mI;
};
int getI(struct Test2 *pthis){
    return pthis->mI;
}
*/


int main(int argc, const char * argv[]) {
    Test t1(10);        // Test(&t1, 10)
    Test t2(20);
    t1.getA();          // getA(&t1)
    return 0;
}
