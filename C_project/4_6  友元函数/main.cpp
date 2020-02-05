//
//  main.cpp
//  4_6  友元函数
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 如果有一个函数经常需要调用getX这种，可以用友元将p1.getX变成p1.x，一般不建议用，破坏封装特性

#include <iostream>
#include <cmath>
using namespace std;

class Point;

class PointManager{
public:
    double PointDistance2(Point &p1, Point &p2);
};



class Point{
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){return this->x;}
    int getY(){return this->y;}
    
    // 声明PointDistance是类Point的一个友元函数
    friend double PointDistance(Point &p1, Point &p2);
    friend double PointManager::PointDistance2(Point &p1, Point &p2);
    
    // friend class B;      友元类
    
private:
    int x;
    int y;
};


double PointDistance(Point &p1, Point &p2){
    double distance;
    int d_x = p1.x - p2.x;
    int d_y = p1.y - p2.y;
    distance = sqrt(d_x * d_x + d_y * d_y);
    return distance;
}

double PointManager::PointDistance2(Point &p1, Point &p2){
    double distance;
    int d_x = p1.x - p2.x;
    int d_y = p1.y - p2.y;
    distance = sqrt(d_x * d_x + d_y * d_y);
    return distance;
}



int main(int argc, const char * argv[]) {
    Point p1(1, 2);
    Point p2(2, 4);
    cout << PointDistance(p1, p2) << endl;
    
    PointManager pm;
    cout << pm.PointDistance2(p1, p2) << endl;
    return 0;
}
