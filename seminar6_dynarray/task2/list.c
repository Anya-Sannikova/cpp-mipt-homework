#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}


static Node* create_node(int value)
{
    Node* p = (Node*)ecmalloc(sizeof(Node));
    p->value = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

static void fail_if_empty(const List* pl, const char* func)
{
    if (pl->size == 0)
    {
        fprintf(stderr, "%s: list is empty.\n", func);
        exit(1);
    }
}


List init(size_t n)
{
    List l;
    l.head = NULL;
    l.tail = NULL;
    l.size = 0;
    for (size_t i = 0; i < n; ++i)
        push_back(&l, 0);
    return l; 
}


void print(const List* pl)
{
    for (const Node* p = pl->head; p != NULL; p = p->next)
        printf("%i ", p->value);
    printf("\n");
}


void push_back(List* pl, int value)
{
    Node* p = create_node(value);
    p->prev = pl->tail;
    if (pl->tail != NULL)
        pl->tail->next = p;
    else
        pl->head = p;
    pl->tail = p;
    pl->size += 1;
}


int pop_back(List* pl)
{
    fail_if_empty(pl, "pop_back");
    Node* p = pl->tail;
    int value = p->value;
    pl->tail = p->prev;
    if (pl->tail != NULL)
        pl->tail->next = NULL; 
    else
        pl->head = NULL; 
    free(p);
    pl->size -= 1;
    return value;
}


void push_front(List* pl, int value)
{
    Node* p = create_node(value);
    p->next = pl->head;
    if (pl->head != NULL)
        pl->head->prev = p;
    else
        pl->tail = p;
    pl->head = p;
    pl->size += 1;
}


int pop_front(List* pl)
{
    fail_if_empty(pl, "pop_front");
    Node* p = pl->head;
    int value = p->value;
    pl->head = p->next;
    if (pl->head != NULL)
        pl->head->prev = NULL;
    else
        pl->tail = NULL;
    free(p);
    pl->size -= 1;
    return value;
}


Node* erase(List* pl, Node* p)
{
    assert(p != NULL);
    Node* next = p->next;

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        pl->head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;
    else
        pl->tail = p->prev;

    free(p);
    pl->size -= 1;
    return next;
}


void splice(List* plist, Node* p, List* pother)
{
    assert(plist != pother);
    if (pother->size == 0)
        return;                 

    Node* first = pother->head; 
    Node* last = pother->tail;

    if (p == NULL)
    {
        if (plist->tail != NULL)
        {
            plist->tail->next = first;
            first->prev = plist->tail;
        }
        else
            plist->head = first;
        plist->tail = last;
    }
    else                      
    {
        Node* before = p->prev; 
        first->prev = before;
        if (before != NULL)
            before->next = first;
        else
            plist->head = first;
        last->next = p;
        p->prev = last;
    }

    plist->size += pother->size;

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}


void destroy(List* pl)
{
    Node* p = pl->head;
    while (p != NULL)
    {
        Node* next = p->next;
        free(p);
        p = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}


void advance(Node** pp, size_t n)
{
    for (size_t i = 0; i < n && *pp != NULL; ++i)
        *pp = (*pp)->next;
}
