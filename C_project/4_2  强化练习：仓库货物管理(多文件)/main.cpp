//
//  main.cpp
//  4_2  强化练习：仓库货物管理(多文件)
//
//  Created by 倪浩鹏 on 2020/2/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
#include "goods.hpp"
using namespace std;


void buy(Goods *&head, int weight){
    Goods *new_goods = new Goods(weight);
    
    if (head == nullptr ) {
        head = new_goods;
    }
    else{                       // 从头插入，头指针本身的地址给new_goods的next，再把new_goods地址给头指针
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
        Goods *tmp = head;
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
            case 0:             //退出
                return 0;
            default:
                break;
        }
        cout << "当前仓库的总重量是：" << Goods::get_m_total_weight() << "kg" << endl;
    } while (1);
    
    return 0;
}
