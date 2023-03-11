#pragma once
#include<Node.h>
using namespace std;


class _List{
        Node* head;
        Node* tail;
    public:
        ~_List();
        void append(int x);
        void appstart(int x);
        void deleteNodeByIndex(int x);
        void deleteNodeByNum(int x);
        Node getNodeByNum(int x);
        Node getNodeByIndex(int x);
} List;


_List::~_List(){

}

void _List::append(int x){
    if(head == nullptr || tail == nullptr){
        head = new Node(x, nullptr, nullptr);
        tail = head;
        return;
    };

    Node* tempPtr = new Node(x, tail, nullptr);
    tail->next = tempPtr;
    tail = tempPtr;
}

void _List::appstart(int x){
    if(head == nullptr || tail == nullptr){
        head = new Node(x, nullptr, nullptr);
        tail = head;
        return;
    };

    Node* tempPtr = new Node(x, head, nullptr);
    head->previous = tempPtr;
    head = tempPtr;
}

void _List::deleteNodeByIndex(int x){
    Node* tempPtr = head;
    for (int i = 0; i < x + 1; i++)
    {
        tempPtr = tempPtr->next;
    }
    tempPtr->previous->next = tempPtr->next;
    tempPtr->next->previous = tempPtr->previous;
    delete tempPtr;
    return;
}

void _List::deleteNodeByNum(int x){
    Node* tempPtr = head;
    for (int i = 0; i < x + 1; i++)
    {
        if(tempPtr->num == x){
            tempPtr->previous->next = tempPtr->next;
            tempPtr->next->previous = tempPtr->previous;
            delete tempPtr;
            break;
        }
        tempPtr = tempPtr->next;
    }
    return;
}

Node _List::getNodeByNum(int x){

}

Node _List::getNodeByIndex(int x){

}