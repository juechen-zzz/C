//
//  main.cpp
//  4_2  强化练习：deque打分案例
//
//  Created by 倪浩鹏 on 2020/3/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    评委打分案例：
        创建5个选手（姓名+得分）
        10个评委对5个选手打分
        去除最高最低分，去平均
        按得分对选手进行排名
 */

#include <iostream>
#include <vector>
#include <deque>
#include "Person.hpp"
using namespace std;

// 创建
void CreatePlayer(vector<Person> &v){
    string NameList = "abcde";
    for (int i = 0; i < 5; i++) {
        string s = "player_";
        s += NameList[i];
        Person p;
        p.SetName(s);
        v.push_back(p);
    }
}

// 打分
void SetScore(vector<Person> &v){
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        deque<double> dScore;
        // 生成分数并保存
        for (int j = 0; j < 10; j++) {
            double s = rand() % 41 + 60.0;
            dScore.push_back(s);
        }
        // 去除最高最低分
        sort(dScore.begin(), dScore.end());
        dScore.pop_front();
        dScore.pop_back();
        
        // 求平均分
        double total_score = 0;
        for (deque<double>::iterator it = dScore.begin(); it != dScore.end(); it++) {
            total_score += (*it);
        }
        double avg = total_score / (double)dScore.size();
        (*i).SetScore(avg);
    }
}

// 排名
bool MyCompare(Person &p1, Person &p2){
    return (p1.GetScore() > p2.GetScore());
}
void Print_Rank(vector<Person> &v){
    // 排序算法
    sort(v.begin(), v.end(), MyCompare);
    // 打印
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        cout << (*i).GetName() << " " << (*i).GetScore() << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<Person> v;
    CreatePlayer(v);
    SetScore(v);
    Print_Rank(v);
    return 0;
}
