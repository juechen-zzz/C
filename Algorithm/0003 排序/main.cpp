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

// 归并排序（递归）
void Merge(vector<int> &nums, vector<int> &tmpnums, int L, int R, int RightEnd){        // 归并函数
    int LeftEnd = R - 1;
    int temp = L;
    int NumElements = RightEnd - L + 1;
    while (L <= LeftEnd && R <= RightEnd) {
        if (nums[L] <= nums[R]) tmpnums[temp++] = nums[L++];
        else tmpnums[temp++] = nums[R++];
    }
    while (L <= LeftEnd) tmpnums[temp++] = nums[L++];
    while (R <= RightEnd) tmpnums[temp++] = nums[R++];
    for (int i = 0; i < NumElements; i++, RightEnd--) {
        nums[RightEnd] = tmpnums[RightEnd];
    }
}
void MSort(vector<int> &nums, vector<int> &tmpnums, int L, int RightEnd){               // 排序算法
    int Center;
    if (L < RightEnd) {
        Center = (L + RightEnd) / 2;
        MSort(nums, tmpnums, L, Center);
        MSort(nums, tmpnums, Center+1, RightEnd);
        Merge(nums, tmpnums, L, Center+1, RightEnd);
    }
}
void MyMergeSort(vector<int> &nums){                                                    // 统一接口
    int N = (int)nums.size();
    vector<int> tmpnums;
    tmpnums.reserve(N);                 // 容器需要预留空间
    MSort(nums, tmpnums, 0, N-1);
}

// 归并排序（非递归）
void Merge1(vector<int> &nums, vector<int> &tmpnums, int L, int R, int RightEnd){        // 归并函数
    int LeftEnd = R - 1;
    int temp = L;
    while (L <= LeftEnd && R <= RightEnd) {
        if (nums[L] <= nums[R]) tmpnums[temp++] = nums[L++];
        else tmpnums[temp++] = nums[R++];
    }
    while (L <= LeftEnd) tmpnums[temp++] = nums[L++];
    while (R <= RightEnd) tmpnums[temp++] = nums[R++];
}
void MergePass(vector<int> &nums, vector<int> &tmpnums, int N, int length){
    int i;
    for (i = 0; i <= N - 2 * length; i += 2 * length) {         // 仅处理到倒数第二对
        Merge1(nums, tmpnums, i, i+length, i+2*length-1);
    }
    if (i + length < N) {                                       // 最后依旧是一对子序列
        Merge1(nums, tmpnums, i, i+length, N-1);
    } else {                                                    // 说明最后只有一个子序列，直接赋值
        for (int j = i; j < N; j++) tmpnums[j] = nums[j];
    }
}
void MyMergeSort1(vector<int> &nums){
    int N = (int)nums.size();
    int length = 1;
    vector<int> tmpnums;
    tmpnums.reserve(N);                                         // 容器需要预留空间
    while (length < N) {                                        // 此处不能有等号情况
        MergePass(nums, tmpnums, N, length);
        length *= 2;
        MergePass(tmpnums, nums, N, length);
        length *= 2;
    }
}

// 快速排序
int Median3(vector<int> &nums, int Left, int Right){
    int Center = (Left + Right) / 2;
    if (nums[Left] > nums[Center]) {
        swap(nums[Left], nums[Center]);
    }
    if (nums[Left] > nums[Right]) {
        swap(nums[Left], nums[Right]);
    }
    if (nums[Center] > nums[Right]) {
        swap(nums[Center], nums[Right]);
    }
    swap(nums[Center], nums[Right-1]);
    return nums[Right-1];
}
void Quicksort(vector<int> &nums, int Left, int Right){
    if (Right - Left >= 2){                         // 小规模数据用快排效率低，小于一个阈值时可以用插入排序，一般阈值为100左右
        int Pivot = Median3(nums, Left, Right);
        int i = Left;
        int j = Right - 1;
        for (; ; ) {
            while (nums[++i] < Pivot) {}
            while (nums[--j] > Pivot) {}
            if (i < j) {
                swap(nums[i], nums[j]);
            } else {break;}
        }
        swap(nums[i], nums[Right-1]);
        Quicksort(nums, Left, i-1);
        Quicksort(nums, i+1, Right);
    }
    else if (Right - Left == 1 && nums[Left] > nums[Right]){
            swap(nums[Left], nums[Right]);
    }
    else {return;}
}
void MyQuickSort(vector<int> &nums){
    int N = (int)nums.size();
    Quicksort(nums, 0, N-1);
}


int main(int argc, const char * argv[]) {
    int a[] = {34, 8, 49, 51, 32, 21};
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
    
//    cout << "堆排序：";
//    MyHeapSort(nums);
//    PrintVector(nums);
    
//    cout << "归并排序（递归）:";
//    MyMergeSort(nums);
//    PrintVector(nums);
    
//    cout << "归并排序（非递归）:";
//    MyMergeSort1(nums);
//    PrintVector(nums);
    
    cout << "快速排序：";
    MyQuickSort(nums);
    PrintVector(nums);
    return 0;
}
