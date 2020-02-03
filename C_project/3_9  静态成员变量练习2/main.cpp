//
//  main.cpp
//  3_9  静态成员变量练习
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class Student{
public:
    Student(int id, double score){
        m_id = id;
        m_score = score;
        m_number++;
        m_all_score += score;
    }
    void printT(){
        cout << "总数为：" << m_number << endl;
        cout << "平均分为：" << (m_all_score / m_number) << endl;
    }
    ~Student(){
        m_number--;
        m_all_score -= m_score;
    }
private:
    int m_id;
    double m_score;
    static double m_all_score;
    static int m_number;
};
int Student::m_number = 0;
double Student::m_all_score = 0;


int main(int argc, const char * argv[]) {
    Student a(1, 45.1);
    Student b(2, 24.6);
    Student c(3, 26.5);
    a.printT();
    return 0;
}
