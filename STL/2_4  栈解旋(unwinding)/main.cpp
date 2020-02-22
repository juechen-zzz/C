//
//  main.cpp
//  2_4  栈解旋(unwinding)
//
//  Created by 倪浩鹏 on 2020/2/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


/*
    栈解旋：当调用函数出现异常时，函数中创建的对象(p1, p2)会自动析构
 */

#include <iostream>
using namespace std;


class Person{
public:
    Person(){
        cout << "Person()" << endl;
    }
    ~Person(){
        cout << "~Person()" << endl;
    }
};

int Divide(int x, int y){
    Person p1, p2;
    
    if (y == 0) {
        throw y;
    }
    return x / y;
}



int main(int argc, const char * argv[]) {
    try {
        Divide(10, 0);
    } catch (int e) {
        cout << "异常捕获：" << e << endl;
    }
    return 0;
}
