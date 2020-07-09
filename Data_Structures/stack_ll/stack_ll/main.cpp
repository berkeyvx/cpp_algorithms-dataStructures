//
//  main.cpp
//  stack
//
//  Created by Berke Yavas on 9.07.2020.
//  Copyright © 2020 Berke Yavas. All rights reserved.
//

// STACK API with linked list
// implementation of stack with linked list
// all operation cost O(1)
// Its slower than array implementation, and uses more memory than array implementation
// Throws std::underflow_error while trying to pop empty stack

#include <iostream>
#include <stdexcept>

typedef struct node_t{
    int data;
    struct node_t *next;
}node_t;


class stack_ll {
    node_t *first = NULL;
    
public:
    
    int pop();
    void push(int data);
    int peek();
    bool isEmpty();
    
    // TODO:: Delete this later
    void debug(){
        node_t *curr = first;
        while(curr != NULL){
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }
};

int stack_ll::pop(){
    if(this->isEmpty()){
        throw std::underflow_error("no data in stack");
    }
    int data = 0;
    data = first->data;
    node_t *oldHead = this->first;
    this->first = this->first->next;
    delete oldHead;
    return data;
}

void stack_ll::push(int data){
    node_t *oldHead = this->first;
    first = new node_t();
    first->data = data;
    first->next = oldHead;
}

bool stack_ll::isEmpty(){
    return first == NULL;
}



int main(int argc, const char * argv[]) {
    stack_ll *stack = new class stack_ll();
    try {
        stack->push(5);
        stack->push(6);
        stack->debug();
        stack->pop();
        stack->debug();
        stack->pop();
        stack->debug();
        stack->pop(); // throws std::underflow_error , must handle it
        stack->push(5);
        stack->push(6);
        stack->debug();
    } catch (std::underflow_error) {
        std::cout << "Underflow error occured";
    }
    return 0;
}
