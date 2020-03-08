//
//  main.cpp
//  STL
//
//  Created by 倪浩鹏 on 2020/2/17.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyPlus{
public:
    int operator()(int val){
        return val + 5;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(31);
    v1.push_back(13);
    
    vector<int> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), MyPlus());
    return 0;
}
