//
//  main.cpp
//  3_5  迭代器案例
//
//  Created by 倪浩鹏 on 2020/2/27.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

int MyCount(int *p_start, int *p_end, int val){
    int num = 0;
    while (p_start != p_end) {
        if (*p_start == val) {
            num++;
        }
        p_start++;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 2, 3, 3, 4, 5, 6};
    int *p_start = arr;
    int *p_end = &(arr[sizeof(arr) / sizeof(int)]);
    int num = MyCount(p_start, p_end, 4);
    cout << "num = " << num << endl;
    return 0;
}
