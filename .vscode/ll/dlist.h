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