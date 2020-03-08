//
//  main.cpp
//  5_3  函数对象
//
//  Created by 倪浩鹏 on 2020/3/8.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    函数对象（仿函数）：实质就是重载()操作符，使得类对象可以像函数那样被调用
    1 函数对象是一个类，不是一个函数
    2 重载()操作符，使得类对象可以像函数那样被调用
    3 若重载的()要求获取一个参数，则为“一元仿函数”；两个就是“二元仿函数”
    4 函数对象超出了函数的概念，可以保持函数调用的状态
    5 若返回值是bool类型，则不称为仿函数，而称为谓词
 */

#include <iostream>
#include <vector>
using namespace std;


class MyPrint{
public:
    MyPrint(){
        this->num = 0;
    }
    void operator()(int val){
        cout << val << endl;
        num++;
    }
    int GetNum(){return this->num;}
private:
    int num;
};

int main(int argc, const char * argv[]) {
    MyPrint p;
    p(1);
    cout << "num: " << p.GetNum() << endl;
    return 0;
}
