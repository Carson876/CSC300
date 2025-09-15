#include "dlist.h"

void insertNode(dnode *&head, dnode *&tail, int value)
{
    dnode* n = new dnode(value);
    if (head == nullptr) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

bool deleteNode(dnode *&head, dnode *&tail, int key)
{
    if (head == nullptr) return false;

   
    if (head->data == key) {
        dnode* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; 
        delete tmp;
        return true;
    }

   
    dnode* cur = head->next;
    while (cur != nullptr) {
        if (cur->data == key) {
            dnode* p = cur->prev;
            dnode* n = cur->next;
            p->next = n;
            if (n) n->prev = p;
            else tail = p; 
            delete cur;
            return true;
        }
        cur = cur->next;
    }
    return false; 
}


void printForward(dnode* head)
{
    for (dnode* w = head; w != nullptr; w = w->next) {
        cout << w->data << (w->next ? " <-> " : "");
    }
    cout << endl;
}


void printBackward(dnode* tail)
{
    for (dnode* w = tail; w != nullptr; w = w->prev) {
        cout << w->data << (w->prev ? " <-> " : "");
    }
    cout << endl;
}
