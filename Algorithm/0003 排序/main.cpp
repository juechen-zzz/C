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
#include <algorithm>
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
                swap(nums[i], nums[i+1]);
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

// 选择排序
void MySelectionSort(vector<int> &nums){
    int N = (int)nums.size();
    for (int i = 0; i < N; i++) {
        int MinPosition = i;
        for (int j = i; j < N; j++){
            if (nums[j] < nums[MinPosition]) {
                MinPosition = j;
            }
        }
        swap(nums[i], nums[MinPosition]);
    }
}

// 堆排序
void HeapAdjust(vector<int> &nums, int s, int m)    //一次筛选的过程
{
    int temp = nums[s];
    for(int j = 2*s+1; j <= m; j = j*2+1)           //通过循环沿较大的孩子结点向下筛选
    {
        if(j < m && nums[j] < nums[j+1]) j++;       //j为较大的记录的下标
        if(temp > nums[j]) break;
        nums[s] = nums[j];
        s = j;
    }
    nums[s] = temp;                                 //插入
}
void MyHeapSort(vector<int> &nums){
    int N = (int)nums.size();
    for (int i = N / 2; i >= 0; i--) {
        HeapAdjust(nums, i, N);                     // 通过循环初始化堆顶
    }
    for (int i = N - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        HeapAdjust(nums, 0, i-1);
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
    
//    cout << "希尔排序：";
//    MyShellSort(nums);
//    PrintVector(nums);
    
//    cout << "选择排序：";
//    MySelectionSort(nums);
//    PrintVector(nums);
    
    cout << "堆排序：";
    MyHeapSort(nums);
    PrintVector(nums);
    return 0;
}
