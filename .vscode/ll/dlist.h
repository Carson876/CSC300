#ifndef DLIST_H
#define DLIST_H

#include <iostream>
using namespace std;

struct dnode {
    int data;
    dnode* prev;
    dnode* next;
    dnode(int d = 0) : data(d), prev(nullptr), next(nullptr) {}
};

void insertNode(dnode *&head, dnode *&tail, int value);


bool deleteNode(dnode *&head, dnode *&tail, int key);

// here if i make a main 
void printForward(dnode* head);
void printBackward(dnode* tail);

#endif