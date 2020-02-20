//
//  main.cpp
//  2_1  MyArray框架实现
//
//  Created by 倪浩鹏 on 2020/2/20.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    // 构造函数
    MyArray(){
        cout << "MyArray():" << endl;
        this->capacity = 0;
        this->address = nullptr;
    }
    MyArray(int capacity){
        cout << "MyArray(int capacity):" << endl;
        if (capacity < 1) {
            return;
        }
        else {
            this->capacity = capacity;
            this->address = new T[this->capacity];
        }
    }
    
    // 拷贝构造
    MyArray(const MyArray<T> &another){
        cout << "MyArray(const MyArray<T> &another):" << endl;
        if (another.capacity > 0) {
            this->capacity = another.capacity;
            // 深拷贝
            this->address = new T[this->capacity];
            for (int i = 0; i < this->capacity; i++) {
                this->address[i] = another.address[i];
            }
        }
    }
    
    // 析构函数
    ~MyArray(){
        cout << "~MyArray()..." << endl;
        if (this->address != nullptr) {
            delete[] this->address;
            this->address = nullptr;
            this->capacity = 0;
        }
    }
    
    // 重载[]
    T& operator[](int index){
        return this->address[index];
    }
    
    // 重载=
    MyArray<T>& operator=(const MyArray<T> &another){
        cout << "MyArray<T>& operator=(const MyArray<T> &another):" << endl;
        if (this == &another) {
            return *this;
        }
        if (this->address != nullptr) {
            delete[] this->address;
            this->address = nullptr;
            this->capacity = 0;
        }
        this->capacity = another.capacity;
        // 深拷贝
        this->address = new T[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            this->address[i] = another.address[i];
        }
        return *this;
    }
    
    // 重载<<
    template<class U>
    friend ostream & operator<<(ostream &os, MyArray<U> &array);
    
    // 设置值函数
    void setData(int index, T data){
        if (this->address != nullptr) {
            this->address[index] = data;
        }
    }
    
    // 取值
    int getC(){return this->capacity;}
    int getS(){return this->size;}
    T getA(){return this->address;}
    
private:
    int capacity;
    T *address;
};

template<class U>
ostream & operator<<(ostream &os, MyArray<U> &array){
    for (int i = 0; i < array.getC(); i++) {
        os << array[i] << " ";
    }
    os << endl;
    return os;
}

int main(int argc, const char * argv[]) {
    MyArray<double> array1(10);
    for (int i = 0; i < 10; i++) {
        array1[i] = i + 1;
    }
    cout << array1;
    
    cout << "----------------------------------------------------" << endl;
    
    MyArray<double> array2 = array1;
    cout << array2;
    
    cout << "----------------------------------------------------" << endl;
    
    MyArray<double> array3;
    array3 = array1;
    cout << array3;
    
    cout << "----------------------------------------------------" << endl;
    
    array3.setData(1, 100.0);
    cout << array3;
    return 0;
}
