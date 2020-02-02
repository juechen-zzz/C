//
//  main.cpp
//  3_8  静态成员变量练习
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

//static成员变量实现了同类对象间信息共享
//只能类外初始化
//static成员类外存储，求类大小时并不包含在内
//static成员是命名空间属于类的全局变量，存储在data区
//可以通过类名访问，也可以通过对象访问


#include <iostream>
using namespace std;


class Box{
public:
    Box(int l, int w){
        length = l;
        width = w;
    }
    void func(){
        cout << "v = " << length * width * height << endl;
    }
    static void change_h(int h){
        height = h;
    }
    
private:
    int length;
    int width;
    static int height;
};
int Box::height = 20;



int main(int argc, const char * argv[]) {
    Box b1(10, 15);
    Box b2(20, 20);
    b1.func();
    b2.func();
    
    
    Box::change_h(30);
    b1.func();
    b2.func();
    return 0;
}
