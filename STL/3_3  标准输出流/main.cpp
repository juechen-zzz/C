//
//  main.cpp
//  3_3  标准输出流
//
//  Created by 倪浩鹏 on 2020/2/26.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    cout.flush()            刷新缓冲区
    cout.put()              向缓冲区写字符，支持链式编程
    cout.write()            二进制流的输出，输出字符串
    cout.width()            输出格式控制
    cout.fill()
    cout.setf()
 */

#include <iostream>
#include <iomanip>
using namespace std;

// cout.flush()
void test1(){
    cout << "hello";
    cout.flush();
}


// cout.put()  cout.write()
void test2(){
    cout.put('h');
    cout.put('l').put('s');
    cout << endl;
    
    cout.write("asdasdasd", strlen("asdasdasd"));
    cout.flush();
}


// 格式化输出
void test3(){
    // 成员方法
    int n = 10;
    cout.unsetf(ios::dec);          // 卸载当前默认的十进制输出方式
    cout.setf(ios::oct);            // 八进制输出
    cout.setf(ios::showbase);       // 显示前面的0
    cout << "八进制：" << n << endl;
    
    cout.unsetf(ios::oct);
    cout.setf(ios::hex);            // 十六进制输出
    cout.setf(ios::showbase);       // 显示前面的0
    cout << "十六进制：" << n << endl;
    
    cout.width(10);                 // 设置输出宽度为10
    cout.fill('$');                 // 空余位置设置用*代替
    cout.setf(ios::left);
    cout << n << endl;
}


// 格式化输出
void test4(){
    // 控制符方式
    int n = 10;
    cout << hex << setiosflags(ios::showbase) << setiosflags(ios::left) << setw(10) << setfill('~') << n << endl;
}


int main(int argc, const char * argv[]) {
    test3();
    return 0;
}
