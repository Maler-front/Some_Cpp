#pragma once
using namespace std;


struct Node
{
    int num;
    Node* next;
    Node* previous;

    Node(int x, Node* next, Node* previous);
};

Node::Node(int x, Node* next, Node* previous){
    num = x;
}
