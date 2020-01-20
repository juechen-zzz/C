//
//  main.cpp
//  C++增强部分
//
//  Created by 倪浩鹏 on 2020/1/20.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;
// C++语言对全局变量的检测增强了

void test(){
    bool flag;          // 新增的bool类型
    flag = true;        // true为1，false为0
    if (flag){
        cout << "Yes!" << endl;
    }
    cout << "size: " << sizeof(flag) << endl;       // 大小为1个字节
}

int main(int argc, const char * argv[]) {
    cout << "Hello, World!" << endl;
    test();
    return 0;
}


//// C语言的写法
//#include <stdio.h>
//
//int main(){
//    int a = 10;
//    int b = 20;
//    printf("%d, %d\n", a, b);
//    return 0;
//}
