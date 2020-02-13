//
//  Cat.hpp
//  7_6  强化练习：动物园案例（多文件）
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Cat_hpp
#define Cat_hpp

#include <iostream>
#include "Animal.hpp"
using namespace std;

class Cat: public Animal{
public:
    virtual void voice();
    ~Cat();
};

#endif /* Cat_hpp */
