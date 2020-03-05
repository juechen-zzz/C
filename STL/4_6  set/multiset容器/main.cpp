//
//  main.cpp
//  4_6  set/multiset容器
//
//  Created by 倪浩鹏 on 2020/3/5.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    set、multiset是基于红黑树的，set不允许重复元素，multiset允许重复元素
    特性：所有元素会根据元素的值自动排序，必须保证插入的元素能够排序，不能通过迭代器改变元素的值（因为会改变顺序）
    insert()/clear()/erase()
 */

#include <iostream>
#include <set>
using namespace std;


// 仿函数，当放入一些对象的时候需要重写比较函数
class MyCompare{
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void PrintSet(set<int, MyCompare> &s){
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

void PrintMultiSet(multiset<int> &s){
    for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}



// 构造函数
void test1(){
    set<int, MyCompare> s1;                // 默认构造,<>中加仿函数进行改变默认排序从小到大
    s1.insert(5);
    s1.insert(8);
    s1.insert(3);
    PrintSet(s1);
    
    set<int, MyCompare> s2(s1);            // 拷贝构造
    PrintSet(s2);
    
    multiset<int> ms1;          // 默认构造
    ms1.insert(2);
    ms1.insert(4);
    ms1.insert(1);
    ms1.insert(1);
    PrintMultiSet(ms1);
    
    multiset<int> ms2;          // =操作符
    ms2 = ms1;
    PrintMultiSet(ms2);
}


// 查找操作
void test2(){
    multiset<int> ms1;          // 默认构造
    ms1.insert(2);
    ms1.insert(4);
    ms1.insert(1);
    ms1.insert(5);
    PrintMultiSet(ms1);
    
    // find(key)        查找键key是否存在，若存在，返回该元素的迭代器；若不存在，返回map.end()
    set<int>::iterator it = ms1.find(5);
    if (it == ms1.end()) {
        cout << "not found" << endl;
    }
    else {
        cout << (*it) << endl;
    }
    
    // lower_bound(keyelem) 返回第一个key >= keyelem元素的迭代器
    cout << *(ms1.lower_bound(2)) << endl;
    
    // upper_bound(keyelem) 返回第一个key > keyelem元素的迭代器
    cout << *(ms1.upper_bound(2)) << endl;
    
    
    // equal_range(keyelem) 返回lower_bound和upper_bound
    // pair(class T1, class T2) 将两种数据类型组合成一个值，常用的键值对(key-value)
    // 创建方式：1 有参    2 make_pair()   3 =操作符
    pair<set<int>::iterator, set<int>::iterator> my_ret = ms1.equal_range(2);
    cout << (*my_ret.first) << endl;
    cout << (*my_ret.second) << endl;
}

  

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
