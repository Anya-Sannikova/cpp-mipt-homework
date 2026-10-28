#pragma once
#include <stddef.h>

// Error checked malloc
void* ecmalloc(size_t n);

struct node
{
    int value;
    struct node* next;
    struct node* prev;  
};
typedef struct node Node;

struct list
{
    Node* head;   
    Node* tail;  
    size_t size; 
};
typedef struct list List;

List init(size_t n);                              // 2.1
void print(const List* pl);                       // 2.2
void push_back(List* pl, int value);              // 2.3
int  pop_back(List* pl);                          // 2.4
void push_front(List* pl, int value);             // 2.5
int  pop_front(List* pl);                         // 2.6
Node* erase(List* pl, Node* p);                   // 2.7
void splice(List* plist, Node* p, List* pother);  // 2.8
void destroy(List* pl);                           // 2.9
void advance(Node** pp, size_t n);                // 2.10
