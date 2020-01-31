//
//  main.cpp
//  2_7 面向过程和面向对象
//
//  Created by 倪浩鹏 on 2020/1/31.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;


// 面向对象
class Dog{
public:
    void eat(){
        cout << name << " eat food" << endl;
    }
    char name[64];
};


// 面向过程
void eat(class Dog &dog){
    cout << dog.name << " eat food " << endl;
}


int main(int argc, const char * argv[]) {
    Dog dog;
    strcpy(dog.name, "ki");
    eat(dog);
    dog.eat();
    return 0;
}
 
