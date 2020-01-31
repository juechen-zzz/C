//
//  main.cpp
//  指针引用
//
//  Created by 倪浩鹏 on 2020/1/23.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

struct teacher{
    int id;
    char name[64];
};

int get_mem(struct teacher **tpp){
    struct teacher *tp = nullptr;
    // malloc指向被分配内存空间的指针
    tp = (struct teacher *)malloc(sizeof(struct teacher));
    if (tp == nullptr) {
        return -1;
    }
    
    tp->id = 100;
    strcpy(tp->name, "li");
    
    *tpp = tp;
    return 0;
}

int get_mem2(struct teacher* &tp){
    tp = (struct teacher*)malloc(sizeof(struct teacher));
    if (tp == nullptr) {
        return -1;
    }
    tp->id = 111;
    strcpy(tp->name, "wang");
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct teacher *tp = nullptr;
    get_mem(&tp);
    cout << "id = " << tp->id << " name = " << tp->name <<endl;
    get_mem2(tp);
    cout << "id = " << tp->id << " name = " << tp->name <<endl;
    free(tp);
    return 0;
}
