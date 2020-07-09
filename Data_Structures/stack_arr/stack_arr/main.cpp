//
//  main.cpp
//  stack_arr
//
//  Created by Berke Yavas on 9.07.2020.
//  Copyright © 2020 Berke Yavas. All rights reserved.
//

// stack implementation using array
// it grows when array is half full
// it shrinks when array is quarter full
// array is between 1/4 or 4/4 full
// Doubling and halving operations are O(N)(worst case)
// Operations take O(1)
// Less wasted space than stack using linked list
// 

#include <iostream>
#include <array>

class stack_arr {
    int index = -1;
    public :int size = 1;
    int *arr = new int[1];
    
private:
    void grow();
    void shrink();
    
public:
    void debug(){
        for (int i = 0; i < index + 1; i++) {
            std::cout << arr[i] << " ";
        }
    }
    
    ~stack_arr(){
        delete [] arr;
    }
    int pop();
    void push(int data);
    bool isEmpty();
    bool isFull();
    int peek();
};


int stack_arr::pop(){
    int data = arr[index--];
    if(index + 1 == size/4){
        shrink();
    }
    return data;
}

void stack_arr::push(int data){
    if (isFull()) {
        grow();
        arr[++index] = data;
    }else
        arr[++index] = data;
}

// Returns true if index equals to -1
bool stack_arr::isEmpty(){
    return index == -1;
}


bool stack_arr::isFull(){
    return index == size - 1;
}

void stack_arr::grow(){
    int *newArr = new int[size*2];
    for(int i = 0; i < size+1; i++){
        newArr[i] = arr[i];
    }
    this->size = size*2;
    delete [] this->arr;
    arr = newArr;
}

void stack_arr::shrink(){
    if(size <= 2){
        return;
    }
    int *newArr = new int[size/4];
    for(int i = 0; i < size+1; i++){
        newArr[i] = arr[i];
    }
    this->size = size/4;
    delete [] this->arr;
    arr = newArr;
}


int main(int argc, const char * argv[]) {
    stack_arr s;
    s.isEmpty();
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(5);
    s.push(6);
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    s.push(1);
    s.push(2);
    s.debug();
    std::cout << "is Empty:" << s.isEmpty() << " is Full:" << s.isFull() << " size:" << s.size;
    return 0;
}
