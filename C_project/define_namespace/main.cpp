//
//  main.cpp
//  define_namespace
//
//  Created by 倪浩鹏 on 2020/1/19.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>

using namespace std;

int g_a = 10;

//定义一个命名空间
namespace spaceA {
    int g_b = 20;
}

namespace spaceB {
    int a = 20;
    namespace spaceC {
        // 定义结构体teacher
        struct teacher{
            int id;
            char name[64];
        };
    }
}

int main(int argc, const char * argv[]) {
    cout << "g_a = " << g_a << endl;
    
    // using spaceA::g_b;
    cout << "g_b = " << spaceA::g_b << endl;
    
    // 调用namespace必须引导到最后一个space，否则也会出现引用歧义
    using namespace spaceB::spaceC;
    struct teacher t1;
    t1.id = 101;
    cout << "t1.id = " << t1.id << endl;
    return 0;
}
 
