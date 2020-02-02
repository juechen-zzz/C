//
//  main.cpp
//  3_1  构造和析构
//
//  Created by 倪浩鹏 on 2020/2/1.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 构造函数：在对象被创建的时候，用来初始化对象的函数，可以重载
// class 类名{
//     类名(形式参数){
// }}

#include <iostream>
using namespace std;

// 默认的构造函数是无参的，一旦提供一个显式的有形参的构造函数，那默认的无参构造函数就不复存在
class Test{
public:
//    void init(int x, int y){
//        m_x = x;
//        m_y = y;
//    }
    Test(int x, int y){
        m_x = x;
        m_y = y;
        
        char *name = (char *)malloc(100);
        strcpy(name, "A");
    }
    
    Test(int x){
        m_x = x;
        m_y = 0;
    }
    
    Test(){         // 无参的构造函数
        m_x = 0;
        m_y = 0;
    }
    
    // 析构函数和构造函数都没有返回值，析构函数没有形参
    // 在一个对象临死之前，触发析构函数，类似于遗言，用来释放堆上的空间，一般为char *这种情况准备
    ~Test(){
        cout << "123" << endl;
//        if (name != nullptr) {
//            free(name);
//        }
    }
    
    void printT(){
        cout << "x = " << m_x << "  y = " << m_y << endl;
    }
    
private:
    int m_x;
    int m_y;
    char *name;
};



int main(int argc, const char * argv[]) {
    // Test t1;
    // 这段时间内t1是无定值的，所以希望在创建时直接有值
    //t1.init(1, 2);
    Test t1(10, 20);
    t1.printT();
    
    Test t2(11);
    t2.printT();
    
    Test t3;
    t3.printT();
    return 0;
}
