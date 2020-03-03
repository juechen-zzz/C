//
//  Person.hpp
//  4_2  强化练习：deque打分案例
//
//  Created by 倪浩鹏 on 2020/3/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
using namespace std;

class Person{
public:
    Person();
    Person(string name, double score);
    string GetName();
    double GetScore();
    void SetScore(double score);
    void SetName(string name);
private:
    string name;
    double score;
};

#endif /* Person_hpp */
