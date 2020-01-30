//
//  main.cpp
//  C_project
//
//  Created by 倪浩鹏 on 2020/1/16.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // cout类似于命令行终端，std是指namespace，endl是指回车，为了兼容全平台
    cout << "Hello, World!" << endl;

    // cin对应于C语言中的scanf
    int a = 0;
    cin >> a;
    cout << "a = " << a << endl;
    return 0;
}

