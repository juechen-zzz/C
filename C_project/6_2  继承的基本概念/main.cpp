//
//  main.cpp
//  6_2  继承的基本概念
//
//  Created by 倪浩鹏 on 2020/2/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


// 父类子类（基类派生类）

#include <iostream>
#include <string>
using namespace std;



class Student{
public:
    Student(int id, string name){
        this->id = id;
        this->name = name;
    }
    void printS(){
        cout << "id = " << this->id << " name = " << this->name << endl;
    }
private:
    int id;
    string name;
};

// 创建一个新的学生类，增加分数功能
class Student2: public Student
{
public:
    // 在调用子类构造函数的时候，会自动调用父类的构造函数，不声明则为无参构造，还有析构函数
    // 重名的时候，加上作用域即可
    Student2(int id, string name, int score): Student(id, name)
    {
        this->score = score;
    }
    void printS(){
        Student::printS();
        cout << "score = " << this->score << endl;
    }
private:
    int score;
};

int main(int argc, const char * argv[]) {
    Student2 s(1, "A", 80);
    s.printS();
    return 0;
}
