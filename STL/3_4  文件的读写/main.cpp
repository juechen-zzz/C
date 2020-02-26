//
//  main.cpp
//  3_4  文件的读写
//
//  Created by 倪浩鹏 on 2020/2/26.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    文件输入流           ifstream(继承于istream,在往上为iostream)
    文件输出流           ofstream(继承于ostream,在往上为iostream)
    文件输入输出流        fstream(继承于iostream)
    文件的打开方式
    文件流的状态
    文件流的定位：文件指针（输入指针、输出指针）
    文本文件和二进制文件
 */

#include <iostream>
#include <fstream>
using namespace std;

// 文本文件读写
void test1(){
    const char *file1 = "/Users/nihaopeng/Code/source.txt";
    const char *file2 = "/Users/nihaopeng/Code/target1.txt";
    ifstream input1(file1, ios::in);                    // 只读方式打开文件
    ofstream output1(file2, ios::out | ios::app);       // app是为了追加写入
    // ifstream input1;
    // input1.open(file, ios::in);
    if (!input1) {
        cout << "打开失败！" << endl;
        return;
    }
    // 读文件
    char ch;
    while (input1.get(ch)) {        // 用get一个字符一个字符的方式可以拷贝回车，用getline和write则无法拷贝回车
        cout << ch;
        output1.put(ch);
    }
    // 关闭文件
    input1.close();
    output1.close();
}



// 二进制文件读写，对象序列化
class Person{
public:
    Person(){}
    Person(int age, int id): age(age), id(id){}
    void show(){cout << age << " " << id << endl;}
private:
    int age;
    int id;
};

void test2(){
    Person p1(10, 1);                                   // 以二进制形式存放在内存中
    Person p2(20, 2);
    // 把p1 p2写进文件
    const char *file2 = "/Users/nihaopeng/Code/target.txt";
    ofstream output2(file2, ios::out | ios::binary);
    output2.write((char *)&p1, sizeof(Person));         // 向文件写入数据
    output2.write((char *)&p2, sizeof(Person));
    output2.close();
    
    // 读取
    ifstream input2(file2, ios::in | ios::binary);
    Person p3, p4;
    input2.read((char *)&p3, sizeof(Person));           // 从文件读取数据
    input2.read((char *)&p4, sizeof(Person));
    p3.show();
    p4.show();
    input2.close();
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
