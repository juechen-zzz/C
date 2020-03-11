//
//  main.cpp
//  0001 最大子列和
//
//  Created by 倪浩鹏 on 2020/3/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

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

// 法二：分治算法
int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
int Max_Sequence_list_2(int arr[], int left, int right){

    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( arr[left] > 0 )  return arr[left];
        else return 0;
    }
    center = ( left + right ) / 2;
    
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = Max_Sequence_list_2(arr, left, center);
    MaxRightSum = Max_Sequence_list_2(arr, center + 1, right);
 
    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += arr[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += arr[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

// 法三：在线处理
int Max_Sequence_list_3(int arr[]){
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < 15; i++) {
        ThisSum += arr[i];                  // 向右累加
        if (ThisSum > MaxSum) {             // 如果大于之前的最大，则更新返回值
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0){              // 出现负值，则清零
            ThisSum = 0;
        }
    }
    return MaxSum;
}

int main(int argc, const char * argv[]) {
    int arr[15] = {1, 5, -6, -2, 8, -3, 1, 5, -2, 6, -4, 3, 2, 6, -9};      // ans = 22
    cout << "最大子列和（暴力搜索）为：" << Max_Sequence_list_1(arr) << endl;
    cout << "最大子列和（分治算法）为：" << Max_Sequence_list_2(arr, 0, 14) << endl;
    cout << "最大子列和（在线处理）为：" << Max_Sequence_list_3(arr) << endl;
    return 0;
}
