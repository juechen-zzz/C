//
//  main.cpp
//  Algorithm
//
//  Created by 倪浩鹏 on 2020/3/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    测试
 */

#include <iostream>
using namespace std;

// 法一：暴力搜索，把所有的子列和全部算一遍，取最小值
int Max_Sequence_list_1(int arr[]){
    int ThisMax, MaxSum = 0;
    for (int i = 0; i < 15; i++) {
        ThisMax = 0;
        for (int j = i; j < 15; j++) {
            ThisMax += arr[j];
            if (ThisMax > MaxSum) {
                MaxSum = ThisMax;
            }
        }
    }
    return MaxSum;
}

int main(int argc, const char * argv[]) {
    int arr[15] = {1, 5, -6, -2, 8, -3, 1, 5, -2, 6, -4, 3, 2, 6, -9};      // ans = 22
    cout << "最大子列和（算法1）为：" << Max_Sequence_list_1(arr) << endl;
    return 0;
}
