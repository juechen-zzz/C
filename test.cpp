//
//  test.cpp
//  C++
//
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 简单写一个冒泡排序
#include <stdio.h>

int main() {
    // insert code here...
    int a[10] = {3, 5, 657, 17, 5};
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
