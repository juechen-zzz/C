//
//  main.cpp
//  5_4  内建函数对象
//
//  Created by 倪浩鹏 on 2020/3/8.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    STL内建的一部分函数对象，头文件functional
    算数：加plus 减minute 乘multiplies 除divides 模modulus 取反negate
    关系：等于equal_to 不等not_equal_to 大于等于greater 大于greater_equal 小于等于less_equal 小于less
    逻辑：与logical_and 或logical_or 非logical_not
 */

#include <iostream>
#include <functional>
using namespace std;


void test1(){
    plus<int> m;
    cout << m(10, 20) << endl;
    
    greater<int> s;
    cout << s(10, 20) << endl;
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
