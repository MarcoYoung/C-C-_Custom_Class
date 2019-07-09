#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>

myList::myList()
{
    head = (Node*)malloc(sizeof(Node));
    if(NULL == head)
        exit(-1);
    head->next = NULL;
}

myList::~myList()
{
    Node* t ;
    while(head != NULL)
    {
        t = head;
        head = head->next;
        free(t);
    }
}

void myList::traverseList()
{
    Node* t = head;
    t = t->next;
    while(t != NULL)
    {
        printf("%d\t",t->data);
        t = t->next;
    }
    putchar(10);
}

int myList::lenList()
{
    int count = 0;
    Node* t = head;
    t = t->next;
    while(t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

void myList::insertList(int data)
{
    Node* cur = (Node*)malloc(sizeof(Node));
    if(NULL == cur)
    {
        printf("Insert failed.\n");
        return;
    }
    cur->data = data;
    cur->next = head->next;
    head->next = cur;
}

Node * myList::searchList(int findData)
{
    Node* t = head;
    t = t->next;
    while(t != NULL)
    {
        if(t->data == findData)
            break;
        t = t->next;
    }
    return t;
}

void myList::deleteNodeInList(Node *pfind)
{
    Node* t;
    t = pfind->next;
    pfind->data = t->data;
    pfind->next = t->next;
    free(t);
}

void myList::popSortList()
{
    Node *pre,*p,*q;
    int num = lenList();
    for(int i=0; i<num-1; i++)
    {
        pre = head;
        p = head->next;
        q = p->next;
        for(int j=0; j<num-1-i; j++)
        {
            if(p->data > q->data)
            {
                p->next = q->next;
                q->next = p;
                pre->next = q;
                pre= q;
                q = p->next;
                continue;
            }
            pre = p;
            p = q;
            q = p->next;
        }
    }
}

void myList::reverseList()
{
    Node* t;
    t = head->next;
    head->next = NULL;

    Node* cur;
    while(t != NULL)
    {
        cur = t;
        t = t->next;
        cur->next = head->next;
        head->next = cur;
    }
}
