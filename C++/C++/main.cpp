//
//  main.cpp
//  C++
//
//  Created by 倪浩鹏 on 2020/1/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 简单写一个冒泡排序
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10] = {3, 1, 4, 5, 2};
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
