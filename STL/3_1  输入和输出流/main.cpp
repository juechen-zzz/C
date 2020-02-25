//
//  main.cpp
//  3_1  输入和输出流
//
//  Created by 倪浩鹏 on 2020/2/25.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    输入和输出，相对于程序来说
    cerr没有缓冲区，clog有缓冲区，都可以理解为标准错误
    endl作用：1 换行  2 清空缓冲区
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";          // cout 全局的流对象
    return 0;
}
