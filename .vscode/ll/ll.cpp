#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if(index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            return;
        }
        else
        {
            newNode->next = walker->next;
            walker->next = newNode;
        }

    }
}

void deleteNode(node *&head, int index) 
{
    // Check if the list is empty and there's nothing to delete

        if (head == nullptr) 
        {
            count << "list is empty" << endl;
            return;
        }

    // Check if were are deleting at index 0 and handle accordingly
    if(index == 0)
    {
        node* rmp = head;
        head = head ->next;
        delete tmp;
    }
    // Handle other index deletions
    else
    {
        node* prev = head;
        int wIndex = 0;

        while (prev !- nullptr && wIndex < index -1)
        {
            prev = prev->next;
            wIndex++;
        }
        if(prev == nullptr || prev->next == nullptr)
        {
            cout << "index is too big, so deletion is not possible" << endl;
            return;
        }
        node* target = prev->next;
        prev->next = target->next;
        delete target;
    }
}

void displayList(node *head) 
 {
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data<<" ";
        walker = walker->next;
    }
    cout<<endl;
    
 }
 
 node* searchNode(node *head, int key)
 {
    for(node* w = head; w != nullptr; w = w->next)
    {
        if(w->data == key)
        return w;
    }
    return nullptr;
 }

 // reverse list using 3 pointer method
 void reverselist(node *&head)
 {
    node* prev = nullptr;
    node* cur = head;
    while( cur != nullpter)
    {
        node* nxt = cur->next;
        cur->next = prev; 
        prev = cur;
        cur = nxt;
    }
    head = prev;
 }