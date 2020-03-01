//
//  main.cpp
//  3_7  String容器
//
//  Created by 倪浩鹏 on 2020/2/29.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    1 string封装了char*，管理这个字符串，是一个char*型的容器
    2 成员方法：find copy delete replace insert/erase append assign compare substr
    3 string管理char*所分配的内存，每一次string的复制，取值都由string类负责维护，不用担心越界
    4 []如果访问越界，程序终止；at()如果访问越界，会抛出异常out_of_range
 */

#include <iostream>
using namespace std;

void test1(){
    string s1;              // 无参
    s1.assign("aaa");
    string s2(3, 'b');     // 有参
    string s3("abc");
    string s4(s3);          // 拷贝构造
    string s5;
    s5 = s3;                // =操作符
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << endl;
    s5.replace(0, 2, "11");
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << endl;
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
