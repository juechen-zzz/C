//
//  Person.cpp
//  4_2  强化练习：deque打分案例
//
//  Created by 倪浩鹏 on 2020/3/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include "Person.hpp"

Person::Person(){
    this->score = 0;
}

Person::Person(string name, double score){
    this->name = name;
    this->score = score;
}

string Person::GetName(){
    return this->name;
}

double Person::GetScore(){
    return this->score;
}

void Person::SetScore(double score){
    this->score = score;
}

void Person::SetName(string name){
    this->name = name;
}
