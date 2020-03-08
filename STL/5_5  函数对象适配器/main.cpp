//
//  main.cpp
//  5_5  函数对象适配器
//
//  Created by 倪浩鹏 on 2020/3/8.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    功能：完成一些配接工作
        bind1st:将参数绑定为函数对象的第一个参数
        bind2nd:将参数绑定为函数对象的第二个参数
        not1:对一元函数对象取反
        not2:对二元函数对象取反
        ptr_fun:将普通函数修饰成函数对象
        mem_fun:修饰成员函数
        mem_fun_ref:修饰成员函数
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////
struct MyPrint: public binary_function<int, int, void>{
    void operator()(int v, int value)const{
        cout << v + value << " ";
    }
};

// 绑定适配器，因为MyPrint本来只能放一个参数，将一个二元的函数对象转换为一元的函数对象
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), 100));
}

////////////////////////////////////////////////////////////////////////////////////

struct MyCompare: public binary_function<int, int, bool>{   // 比较
    bool operator()(int a, int b)const{
        return a > b;
    }
};
struct MyPrint2{        // 打印
    void operator()(int v){
        cout << v << " ";
    }
};
struct MyGreater: public unary_function<int, bool>{       // 取大于50的第一个值
    bool operator()(int v)const{
        return v > 50;
    }
};

// 取反适配器
void test2(){
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 100);
    }
    for_each(v.begin(), v.end(), MyPrint2());cout << endl;
    sort(v.begin(), v.end(), not2(MyCompare()));            // not2取反，依旧从小到大排序
    for_each(v.begin(), v.end(), MyPrint2());cout << endl;
    
    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreater()));   // not1取反
    cout << "小于50的第一个值：" << (*it) << endl;
}

////////////////////////////////////////////////////////////////////////////////////

// 仿函数适配器ptr_fun
void MyPrint3(int val, int a){
    cout << val + a << " ";
}
void test3(){
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 100);
    }
    // 把普通函数适配为函数对象
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint3), 10));cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////

// mem_fun/mem_fun_ref:修饰成员函数，如果容器中存放的是对象或者对象指针，for_each能够调用类自带的打印函数
class Person{
public:
    Person(int age, int id):age(age), id(id){}
    void PrintShow(){
        cout << this->id << ":" << this->age << endl;
    }
    int age;
    int id;
};
void test4(){
    vector<Person> v;
    Person p1(10, 1), p2(20, 2), p3(30, 3), p4(40, 4);
    v.push_back(p1);v.push_back(p2);v.push_back(p3);v.push_back(p4);
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::PrintShow));          // 格式
    
    vector<Person*> v1;
    v1.push_back(&p1);v1.push_back(&p2);v1.push_back(&p3);v1.push_back(&p4);
    for_each(v1.begin(), v1.end(), mem_fun(&Person::PrintShow));            // 格式
    // for_each(v1.begin(), v1.end(), mem_fn(&Person::PrintShow));          上述两种已被删除，整合成mem_fn
}

int main(int argc, const char * argv[]) {
    test4();
    return 0;
}
