//
//  main.cpp
//  7_6  强化练习：动物园案例（多文件）
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 建议抽象类的析构函数写成虚析构函数，防止内存泄漏

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
//    Animal *c = new Cat;
//    PrintS(c);
//    delete c;
    
    PrintS(new Cat);
    return 0;
}
