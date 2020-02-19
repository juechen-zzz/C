//
//  main.cpp
//  1_6  类模板外部实现（多文件）
//
//  Created by 倪浩鹏 on 2020/2/20.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
   类模板多文件形式下不能分成.h和.cpp写，而是要写在一起，一般命名为.hpp
   类模板中的static对象会根据不同类型分开，A<int>和A<double>不共享static，但其内部共享
*/

#include <iostream>
#include "Person.hpp"

int main(int argc, const char * argv[]) {
    Person<int> p(10, 1);
    p.PrintS();
    cout << p;
    PrintPerson(p);
    return 0;
}
