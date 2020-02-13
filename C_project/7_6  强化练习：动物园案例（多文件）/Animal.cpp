//
//  Animal.cpp
//  7_6  强化练习：动物园案例（多文件）
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "Animal.hpp"
void PrintS(Animal *animal){
    animal->voice();
    if (animal != nullptr) {
        delete animal;
    }
}

Animal::~Animal(){
    cout << "~Animal().." << endl;
}
