//
//  main.cpp
//  6_3  继承的方式
//
//  Created by 倪浩鹏 on 2020/2/10.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


/*
               public      protected       private
    公有继承：   public      protected       不可见
    保护继承：  protected    protected       不可见
    私有继承：   private      private        不可见
 */

// 若在子类的内部可以访问，外部不可访问，可能是私有，也有可能是保护，需要看子类的子类能否访问


#include <iostream>
using namespace std;

class Parent{
public:             // 类的内部和外部都可以访问
    int pub = 1;
protected:          // 类的内部可以访问，外部不可访问
    int pro = 2;
private:            // 类的内部可以访问，外部不可访问
    int pri = 3;
};

// 公有继承
class Child: public Parent{
public:
    void func(){
        cout << pub << endl;        // 父类的public成员变量，在继承类的内部和外部都可以访问
        cout << pro << endl;        // 父类的protected成员变量，在继承类的内部可以访问，外部不可访问
        //cout << pri << endl;      // 父类的private成员变量，在继承类的内部和外部都不可以访问
    }
};

int main(int argc, const char * argv[]) {
    Child c1;
    c1.func();
    
    return 0;
}
