//
//  main.cpp
//  7_4  强化练习：工厂问题（抽象类）
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class Factory{
public:
    virtual void fight() = 0;
};

class A: public Factory
{
public:
    A(string name){
        this->name = name;
    }
    virtual void fight(){
        cout << "A:" << this->name << endl;
    }
private:
    string name;
};

int main(int argc, const char * argv[]) {
    Factory *s1 = new A("aa");
    s1->fight();
    string name[64] = {"1", "2"};
    cout << name[1] << endl;
    return 0;
}
