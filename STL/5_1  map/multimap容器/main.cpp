//
//  main.cpp
//  5_1  map/multimap容器
//
//  Created by 倪浩鹏 on 2020/3/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
map/multimap容器：
    map相对于set的区别：map具有键值和实值（字典），所有元素根据键值(key)自动排序，pair为<key, value>
    以红黑树为底层实现机制
    map中key不可重复，multimap可以重复；
 */

#include <iostream>
#include <map>
using namespace std;


void PrintMap(map<int, int> &m){
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << "-" << (*it).second << " ";          // it->first也可
    }
    cout << endl;
}

// 构造,初始化
void test1(){
    map<int, int> m1;                               // 第一个是key类型，第二个是value类型
    
    // 插入数据的四种方式
    // 前三种都不能第二次插入到同一个key里面，第四种则可以覆盖
    // 如果通过[]访问一个不存在的key，则会自动创建一个Pair，并且value=0
    m1.insert(make_pair(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(map<int, int>::value_type(3, 30));    // Map内置的赋值方式
    m1[4] = 40;                                     // 类似于数组进行赋值
    m1[4] = 33;
    PrintMap(m1);
}


class Mykey{
public:
    Mykey(int index, int ID){
        this->index = index;
        this->ID = ID;
    }
    int GetIndex(){return this->index;}
    int GetID(){return this->ID;}
    int index;
    int ID;
};

struct MyCompare123{
    bool operator()(Mykey k1, Mykey k2)const{
        return (k1.index > k2.index);
    }
};

void test2(){
    map<Mykey, int, MyCompare123> m2;
    Mykey s1(1, 10);
    //m2.insert(make_pair(s1, 100));
    m2[s1] = 100;
    m2.insert(make_pair(Mykey(2, 20), 200));
}




int main(int argc, const char * argv[]) {
    //test1();
    test2();
    return 0;
}
