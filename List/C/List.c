#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>

Node * createList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if(NULL == head)
        return NULL;
    head->next = NULL;
    return head;
}

void traverseList(Node *head)
{
    head = head->next;
    while(head != NULL)
    {
        printf("%d\t",head->data);
        head = head->next;
    }
    putchar(10);
}

int lenList(Node *head)
{
    int count = 0;
    head = head->next;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertList(Node * head, int data)
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

Node * searchList(Node * head,int findData)
{
    head = head->next;
    while(head != NULL)
    {
        if(head->data == findData)
            break;
        head = head->next;
    }
    return head;
}

void deleteNodeInList(Node *pfind)
{
    Node* t;
    t = pfind->next;
    pfind->data = t->data;
    pfind->next = t->next;
    free(t);
}

void popSortList(Node *head)
{
    Node *pre,*p,*q;
    int num = lenList(head);
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

void destroyList(Node *head)
{
    Node* t ;
    while(head != NULL)
    {
        t = head;
        head = head->next;
        free(t);
    }
}

void reverseList(Node *head)
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
