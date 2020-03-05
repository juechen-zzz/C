//
//  main.cpp
//  4_5  list容器
//
//  Created by 倪浩鹏 on 2020/3/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    链表：由一系列节点组成，节点包含两个属性（数据域+指针域）
    1 链表的内存是非连续的，添加删除元素的时间复杂度都是常数项，不需要数据元素移动
    2 链表只有在需要的时候才会分配内存
    3 链表需要额外的空间保存节点关系
    push_front()/pop_front()    push_back()/pop_back()
    insert(pos, elem)           clear()/erase()     清空/删除
    remove(elem)     删除所有匹配值
 */


#include <iostream>
#include <list>
using namespace std;


void PrintList(list<int> &l){
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

// 初始化
void test1(){
    list<int> l1;
    list<int> l2(10, 2);        // 有参构造
    list<int> l3(l2);
    list<int> l4(l3.begin(), l3.end());
    PrintList(l4);
}


bool MyCompare(int a, int b){
    return (a > b);
}

// 大小赋值操作
void test2(){
    list<int> l1;
    l1.assign(3, 2);
    PrintList(l1);
    
    l1.push_back(5);
    PrintList(l1);
    
    l1.reverse();       // 反转
    PrintList(l1);
    
    l1.sort();          // 排序，是list的成员函数，默认从小到大
    PrintList(l1);
    
    l1.sort(MyCompare); // 算法sort支持可随机访问的容器，list不支持随机访问
    PrintList(l1);
}

int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
