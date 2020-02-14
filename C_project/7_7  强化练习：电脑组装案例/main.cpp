//
//  main.cpp
//  7_7  强化练习：电脑组装案例
//
//  Created by 倪浩鹏 on 2020/2/14.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// ---------------抽象层-----------------
class CPU{
public:
    virtual void calculate() = 0;
};

class Card{
public:
    virtual void display() = 0;
};

class Memory{
public:
    virtual void storage() = 0;
};

// 关键点，将前三个抽象类组合
class Computer{
public:
    Computer(CPU *cpu, Card *card, Memory *memory){
        this->cpu = cpu;
        this->card = card;
        this->memory = memory;
    }
    void work(){
        cout << "电脑配置为：" << endl;
        this->cpu->calculate();
        this->card->display();
        this->memory->storage();
    }
    ~Computer(){
        if (this->cpu != nullptr) {
            delete this->cpu;
        }
        if (this->card != nullptr) {
            delete this->card;
        }
        if (this->memory != nullptr) {
            delete this->memory;
        }
    }
private:
    CPU *cpu;
    Card *card;
    Memory *memory;
};

// ---------------实现层-----------------
class IntelCPU: public CPU{
    virtual void calculate(){
        cout << "Intel CPU" << endl;
    }
};

class IntelCard: public Card{
    virtual void display(){
        cout << "Intel Card" << endl;
    }
};

class IntelMemory: public Memory{
    virtual void storage(){
        cout << "Intel Memory" << endl;
    }
};
// -------------------------------------

// -------------业务逻辑层----------------
int main(int argc, const char * argv[]) {
    CPU *cpu = new IntelCPU;
    Card *card = new IntelCard;
    Memory *memory = new IntelMemory;
    
    Computer *c1 = new Computer(cpu, card, memory);
    c1->work();
    
    Computer *c2 = new Computer(new IntelCPU, new IntelCard, new IntelMemory);
    c2->work();
    return 0;
}
