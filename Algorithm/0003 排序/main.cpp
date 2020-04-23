//
//  main.cpp
//  0003 排序
//
//  Created by 倪浩鹏 on 2020/4/21.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 将各种排序记录一下

#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> &nums){
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

// 冒泡排序
void MyBubbleSort(vector<int> &nums){
    int N = (int)nums.size();
    for (int p = N-1; p >= 0; p--) {
        bool flag = true;                           // 用来判断是否可以提前结束
        for (int i = 0; i < p; i++){
            if (nums[i] > nums[i+1]) {
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                flag = false;
            }
        }
        if (flag) {break;}
    }
}

// 插入排序
void MyInsertionSort(vector<int> &nums){
    int N = (int)nums.size();
    for (int p = 1; p < N; p++) {
        int temp = nums[p];
        int i;
        for (i = p; i > 0 && nums[i-1] > temp; i--) {
            nums[i] = nums[i-1];
        }
        nums[i] = temp;
    }
}

// 希尔排序(原始增量序列)
void MyShellSort(vector<int> &nums){
    int N = (int)nums.size();
    for (int D = N/2; D > 0; D /= 2) {
        for (int p = D; p < N; p++) {
            int temp = nums[p];
            int i;
            for (i = p; i > 0 && nums[i-D] > temp; i -= D) {
                nums[i] = nums[i-D];
            }
            nums[i] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int a[] = {34, 8, 64, 51, 32, 21};
    vector<int> nums(a, a+6);
    cout << "初始数组：";
    PrintVector(nums);
    
//    cout << "冒泡排序：";
//    MyBubbleSort(nums);
//    PrintVector(nums);
    
//    cout << "插入排序：";
//    MyInsertionSort(nums);
//    PrintVector(nums);
    
    cout << "希尔排序：";
    MyShellSort(nums);
    PrintVector(nums);
    return 0;
}
