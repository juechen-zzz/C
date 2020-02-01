//
//  main.cpp
//  3_4  深拷贝和浅拷贝
//
//  Created by 倪浩鹏 on 2020/2/1.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class Teacher{
public:
    Teacher(int id, const char *name){
        m_id = id;
        
        double len = strlen(name);
        m_name = (char *)malloc(len + 1);       // 在栈上开辟空间，存在\0m，所以长度+1
        strcpy(m_name, name);
    }
    
    void printT(){
        cout << "ID = " << m_id << "  Name = " << m_name << endl;
    }
    
    // 修改拷贝构造函数，完成深拷贝
    Teacher(const Teacher &another){
        m_id = another.m_id;
        
        // 深拷贝操作
        double len = strlen(another.m_name);
        m_name = (char *)malloc(len + 1);       // 在栈上开辟空间，存在\0，所以长度+1
        strcpy(m_name, another.m_name);
    }
    
    ~Teacher(){
        cout << "~Teacher()..." << endl;
        if (m_name != nullptr) {
            free(m_name);
            m_name = nullptr;
        }
    }
    
private:
    int m_id;
    char *m_name;       // char name[64]
};



int main(int argc, const char * argv[]) {
    Teacher t1(1, "AAAAA");
    t1.printT();
    
    Teacher t2(t1);
    t2.printT();
//  默认拷贝，t1和t2的name指针指向同一个区域（浅拷贝）
//  这种方式是错误的，因为调用了~Teacher析构函数，t2创建完会释放空间，把name指针指向区域清空了
    return 0;
}
