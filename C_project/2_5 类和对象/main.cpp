//
//  main.cpp
//  2_5 类和对象
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 用法类似于结构体
// 区别：类class有访问控制权限，封装的特性，而结构体没有
// class默认访问权限为private，结构体默认为public
struct Hero {
    char name[64];
    int id;
};

void printHero(struct Hero &h){
    cout << "Hero" << endl;
}


class A_Hero{
public:                             // 访问控制权限，public内外都可以访问，private只能在内部访问
    char name[64];
    int sex;
    
    void printHero(){
        cout << "A hero" << endl;
    }
private:
    int id;
};

int main(int argc, const char * argv[]) {
    Hero z;
    printHero(z);
    
    
    A_Hero h;
    h.sex = 1;
    strcpy(h.name, "abc");
    cout << h.sex << " " << h.name << endl;
    h.printHero();
    return 0;
}
