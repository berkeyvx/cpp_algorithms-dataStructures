//
//  main.cpp
//  queue_ll
//
//  Created by Berke Yavas on 9.07.2020.
//  Copyright © 2020 Berke Yavas. All rights reserved.
//

// Throws std::underflow_error if dequeue empty queue.
// All operations O(1)

#include <iostream>
#include <stdexcept>

struct linkedListNode{
    int data;
    struct linkedListNode *next;
};

class queue_ll {
    typedef struct linkedListNode node_t;
    node_t *head = nullptr;
    node_t *tail = nullptr;
    int s = 0;
    
public:
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    int size();
    
    void debug(){
        while(head != nullptr){
            std::cout << head->data << " ";
            head = head->next;
        }
    }
};

void queue_ll::enqueue(int data){
    node_t *oldTail = tail;
    tail = new node_t();
    tail->data = data;
    tail->next = nullptr;
    if (isEmpty()) {
        head = tail;
    }else{
        oldTail->next = tail;
    }
    s++;
}

int queue_ll::dequeue(){
    if(this->size() == 0){
        throw std::underflow_error("no data in queue");
    }
    int data = head->data;
    node_t *delPtr = head; // save adresses of head to delete
    head = head->next;
    delete delPtr; // delete old head and free memory
    s--;
    return data;
}

bool queue_ll::isEmpty(){
    return head == nullptr;
}

int queue_ll::size(){
    return s;
}

int main(int argc, const char * argv[]) {
    queue_ll *q = new class queue_ll();
    q->enqueue(3);
    q->enqueue(5);
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->debug();
    return 0;
}
