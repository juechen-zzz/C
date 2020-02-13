//
//  Animal.hpp
//  7_6  强化练习：动物园案例（多文件）
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
using namespace std;

class Animal{
public:
    virtual void voice() = 0;
    virtual ~Animal();
};

void PrintS(Animal *animal);

#endif /* Animal_hpp */
