//
//  main.cpp
//  1_3  强化练习：模板实现排序(冒泡)
//
//  Created by 倪浩鹏 on 2020/2/17.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
void Sort1111(T *a, int len){
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (a[i] > a[j]) {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

template<class T>
void PrintS(T *arr, int len){
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    int arr[] = {3, 5, 1, 2, 6};
    int len = sizeof(arr) / sizeof(int);
    Sort1111(arr, len);
    PrintS(arr, len);
    
    char arr1[] = {'a', 'c', 'b'};
    int len2 = sizeof(arr1) / sizeof(char);
    Sort1111(arr1, len2);
    PrintS(arr1, len2);
    return 0;
}
