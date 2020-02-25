//
//  main.cpp
//  3_2  标准输入流
//
//  Created by 倪浩鹏 on 2020/2/25.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    cin.get()               一次只能读取一个字符
    cin.get(一个参数)         读一个字符
    cin.get(两个参数)         可以读字符串
    cin.getline()           读取一行数据
    cin.ignore()            忽略当前字符
    cin.peek()              看一看缓冲区的第一个字符，不取走
    cin.putback()           一般和cin.get()配合使用，get从缓冲区拿走，putback放回
 */


#include <iostream>
using namespace std;

// 标准输入流 cin.get()
void test1(){
    char c;
    while ((c = cin.get()) != EOF) {
        cout << c << endl;
    }

    char c2;
    cin.get(c2);        // 读取一个字符
    cout << c2 << endl;
    
    char b[256] = {0};
    cin.get(b, 256);    // 从缓冲区读一个字符串
    cin.getline(b, 256);
    cout << b << endl;
}


// cin.ignore()
void test2(){
    char c;
    cin.get(c);
    cout << c << endl;
    
    cin.ignore(2);          // 忽略当前字符(已经提取过第一个，忽略后面2个字符)
    cin.ignore(10, '\n');   // 忽略10个字符，如果遇到\n则忽略之前的字符
    
    cin.get(c);
    cout << c << endl;
}


// cin.peek()       看一看缓冲区的第一个字符，不取走
void test3(){
    char c;
    c = cin.peek();
    if (c >= '0' &&  c <= '9') {
        int number;
        cin >> number;
        cout << "数字:" << number << endl;
    }
    else {
        char b[256] = {0};
        cin >> b;
        cout << "字符:" << b << endl;
    }
}


// cin.putback()        一般和cin.get()配合使用
void test4(){
    char c;
    cin.get(c);
    if (c >= '0' &&  c <= '9') {
        cin.putback(c);
        int number;
        cin >> number;
        cout << "数字:" << number << endl;
    }
    else {
        cin.putback(c);
        char b[256] = {0};
        cin >> b;
        cout << "字符:" << b << endl;
    }
}


int main(int argc, const char * argv[]) {
    test4();
    return 0;
}
