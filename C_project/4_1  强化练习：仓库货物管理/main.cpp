//
//  main.cpp
//  4_1  强化练习：仓库货物管理
//
//  Created by 倪浩鹏 on 2020/2/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

//某商店经销一种货物，货物购进和卖出时以箱为单位，各箱的重量不一样。
//因此，商店需要记录目前库存的总重量，来模拟商店购进和卖出的情况。



#include <iostream>
using namespace std;

class Goods{
public:
    // 构造函数
    Goods(){
        m_weight = 0;
        next = nullptr;
        cout << "创建了一个重量为" << m_weight << "kg的货物" << endl;
    }
    Goods(int weight){
        m_weight = weight;
        next = nullptr;
        m_total_weight += m_weight;
        cout << "创建了一个重量为" << m_weight << "kg的货物" << endl;
    }
    // 创建指针
    Goods *next;
    // 析构函数
    ~Goods(){
        cout << "删除了一个重量为" << m_weight << "kg的货物" << endl;
        m_total_weight -= m_weight;
    }
    // 静态成员方法
    static int get_m_total_weight(){
        return m_total_weight;
    }

private:
    int m_weight;                    // 每个的重量
    static int m_total_weight;       // 总重量
};
int Goods::m_total_weight = 0;




void buy(Goods *&head, int weight){
    Goods *new_goods = new Goods(weight);
    
    if (head == nullptr ) {
        head = new_goods;
    }
    else{       // 从头插入，头指针本身的地址给new_goods的next，再把new_goods地址给头指针
        new_goods->next = head;
        head = new_goods;
    }
}

void sale(Goods *&head){
    if (head == nullptr) {
        cout << "无货！" << endl;
        return;
    }
    else{
        Goods * tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main(int argc, const char * argv[]) {
    int choice = 0;
    int weight;
    Goods *head = nullptr;
    do {
        cout << "1 进货 | 2 出货 | 0 退出" << endl;
        cin >> choice;
        switch (choice) {
            case 1:             //进货
                cout << "请输入要创建货物的重量：";
                cin >> weight;
                buy(head, weight);
                break;
            case 2:             //出货
                sale(head);
                break;
            case 0:             //退出ß
                return 0;
            default:
                break;
        }
        cout << "当前仓库的总重量是：" << Goods::get_m_total_weight() << "kg" << endl;
    } while (1);
    
    return 0;
}
