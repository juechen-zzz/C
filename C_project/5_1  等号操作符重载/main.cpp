//
//  main.cpp
//  5_1  等号操作符重载
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class Student{
public:
    Student(){
        this->id = 0;
        this->name = nullptr;
    }
    
    Student(int id, const char *name){
        this->id = id;
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
    }
    
    ~Student(){
        if (this->name != nullptr) {
            delete[] this->name;
            this->name = nullptr;
            this->id = 0;
        }
    }
    
    // 拷贝构造函数
    Student(const Student &another){
        this->id = another.id;
        
        // 深拷贝
        double len = strlen(another.name);
        this->name = new char(len + 1);
        strcpy(this->name, another.name);
    }
    
    // 等号操作符重载
    Student &operator=(const Student &another){
        if (this == &another) {         // 1 防止自身赋值
            return *this;
        }
        if (this->name != nullptr) {    // 2 删除之前的开辟空间
            delete[] this->name;
            this->name = nullptr;
            this->id = 0;
        }
        this->id = another.id;          // 3 深拷贝
        double len = strlen(another.name);
        this->name = new char(len + 1);
        strcpy(this->name, another.name);
        return *this;
    }
    void printS(){
        cout << this->name << endl;
    }
private:
    int id;
    char *name;
};



int main(int argc, const char * argv[]) {
    Student s1(1, "A");
    Student s2 = s1;
    s1.printS();
    s2.printS();
    
    Student s3(2, "B");
    s2 = s3;
    s2.printS();
    return 0;
}
