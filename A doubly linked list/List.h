#include<Node.h>
using namespace std;


class _List{
    private:
        Node* head;
        Node* tail;
        unsigned int countMembers;
    public:
        _List();
        ~_List();
        unsigned int length();
        void append(int x);
        void appstart(int x);
        void deleteNodeByIndex(int x);
        void deleteNodeByNum(int x);
        Node* getNodeByNum(int x);
        Node* getNodeByIndex(int x);
} List;


_List::_List(){
    head = nullptr;
    tail = nullptr;
    countMembers = 0;
}

_List::~_List(){
    for(int i = 0; i < countMembers; i++)
        deleteNodeByIndex(0);
}

unsigned int _List::length(){
    return countMembers;
}

void _List::append(int x){
    if(head == nullptr || tail == nullptr){
        head = new Node(x, nullptr, nullptr);
        tail = head;
        countMembers++;
        return;
    };

    Node* tempPtr = new Node(x, nullptr, tail);
    tail->next = tempPtr;
    tail = tempPtr;
    countMembers++;
}

void _List::appstart(int x){
    if(head == nullptr || tail == nullptr){
        head = new Node(x, nullptr, nullptr);
        tail = head;
        countMembers++;
        return;
    };

    Node* tempPtr = new Node(x, head, nullptr);
    head->previous = tempPtr;
    head = tempPtr;
    countMembers++;
}

void _List::deleteNodeByIndex(int x){
    Node* tempPtr = getNodeByIndex(x);
    if(tempPtr == nullptr)
        return;
    
    tempPtr->previous->next = tempPtr->next;
    tempPtr->next->previous = tempPtr->previous;
    delete tempPtr;
    countMembers--;
}

void _List::deleteNodeByNum(int x){
    Node* tempPtr = getNodeByNum(x);
    if(tempPtr == nullptr)
        return;

    tempPtr->previous->next = tempPtr->next;
    tempPtr->next->previous = tempPtr->previous;
    delete tempPtr;
    countMembers--;
}

Node* _List::getNodeByNum(int x){
    Node* tempPtr = head;
    for (int i = 0; i < countMembers; i++){
        if(tempPtr->num == x){
            return tempPtr;
        }
    }
    return nullptr;
}

Node* _List::getNodeByIndex(int x){
    if((x + 1) > countMembers || x < 0)
        return nullptr;

    Node* tempPtr = head;
    for (int i = 0; i < x; i++)
    {
        tempPtr = tempPtr->next;
    }
    return tempPtr;
}