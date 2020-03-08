//
//  main.cpp
//  3_8  vector动态数组
//
//  Created by 倪浩鹏 on 2020/2/29.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    容器特性：单口容器(push_back/pop_back)
    只有queue和stack是不提供迭代器的
    如果原先的内存空间不足，会重新申请一块更大的内存空间同时拷贝数据，并将原先的内存空间释放掉
    注意：如果对象中有指针，并且要添加进容器中，必须重写构造函数、拷贝构造函数和=操作符（深拷贝）
    v.begin()返回一个迭代器，指向容器中第一个元素               v.rbegin()返回一个迭代器，指向容器中最后一个元素
    v.end()返回一个迭代器，指向容器中最后一个元素的下一个地址      v.rend()返回一个迭代器，指向容器中第一个元素
    v.front()/v.back()返回第一个/最后一个元素，并非迭代器
    v.resize()既修改capacity大小，也修改size大小
    v.reserve()只修改capacity大小，不修改size大小
 */

#include <iostream>
#include <vector>
using namespace std;


void PrintVector(vector<int> &v){
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

// 初始化
void test1(){
    vector<int> a1;
    
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a2(arr, arr + sizeof(arr) / sizeof(int));   // vector<T> v(a.begin(), a.end())
    PrintVector(a2);
    
    vector<int> a3(a2);     // 拷贝构造
    PrintVector(a3);
}



// 常用赋值操作
void test2(){
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a1(arr, arr + sizeof(arr) / sizeof(int));
    PrintVector(a1);
    
    // assign赋值
    vector<int> a2;
    a2.assign(a1.begin(), a1.end());
    PrintVector(a2);
    
    // 重载=
    vector<int> a3;
    a3 = a2;
    PrintVector(a3);
    
    // swap交换
    int arr2[] = {1, 2};
    vector<int> a4(arr2, arr2 + sizeof(arr2) / sizeof(int));
    a3.swap(a4);    // 将指针交换
    PrintVector(a3);
    PrintVector(a4);
}



// 大小操作
void test3(){
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a1(arr, arr + sizeof(arr) / sizeof(int));
    cout << a1.size() << endl;      // size()返回容器中元素的个数
    
    cout << a1.empty() << endl;     // empty()判断容器是否为空
    
    a1.resize(8);                   // resize(int num) 重新指定容器长度，若变长，则以默认值0填充；若变短，多余的元素删除
    PrintVector(a1);
    
    cout << a1.size() << endl;
    cout << a1.capacity() << endl;  // 容器的容量：对于变大的情况,resize()既修改capacity大小，也修改size大小
                                    //          对于变小的情况，resize()只修改size大小，不修改capacity
                                    // 容器是线性表，内存空间是连续的，每次添加一个新元素，系统可能会自动分配额外的存储空间
    
    a1.reserve(20);                 // reserve()预留空间，只修改capacity大小，不修改size大小
    cout << a1.size() << endl;
    cout << a1.capacity() << endl;
}


// 插入和删除
void test4(){
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a1(arr, arr + sizeof(arr) / sizeof(int));
    
    a1.insert(a1.begin() + 1, 2, 3);    // insert(iter_pos, num, elm)
    PrintVector(a1);                    // vector支持随机访问，支持数组下标访问，迭代器可以+2
    
    a1.erase(a1.end() - 1);             // erase(begin, end);  erase(pos);
    PrintVector(a1);
    
    // clear() 清空
    // 收缩空间
    // vector<int>(v).swap(v);
}


int main(int argc, const char * argv[]) {
    test3();
    return 0;
}
