//
//  main.cpp
//  6_5  多继承
//
//  Created by 倪浩鹏 on 2020/2/11.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    多继承与虚继承，Bed和Sofa都是Furniture的子类，对于Furniture中的成员变量m
    解决方法：加virtual关键字，这样最后SofaBed中只有1个m
 */

#include <iostream>
using namespace std;

class Furniture{
public:
    int m;
};


class Bed: virtual public Furniture{
public:
    void printS(){
        cout << "Sleep on the bed" << endl;
    }
private:
};

class Sofa: virtual public Furniture{
public:
    void sit(){
        cout << "On the sofa" << endl;
    }
};

// 多继承
class SofaBed: public Bed, public Sofa{
public:
    void sleep_and_sit(){
        printS();
        sit();
    }
};


int main(int argc, const char * argv[]) {
    Bed b;
    Sofa s;
    b.printS();
    s.sit();
    
    cout << "------------------------------" << endl;
    
    SofaBed sb;
    sb.sleep_and_sit();
    
    sb.m = 100;             // 本来是错误的写法，此时SofaBed中有两个m，多继承的弊端，加virtual关键字解决
                            // sb.Bed::m = 100;
                            // sb.Sofa::m = 200;
    return 0;
}
