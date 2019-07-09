#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>

template<typename T>
myList<T>::myList()
{
    head = (Node<T>*)malloc(sizeof(Node<T>));
    if(NULL == head)
        exit(-1);
    head->next = NULL;
}

template<typename T>
myList<T>::~myList()
{
    Node<T>* t ;
    while(head != NULL)
    {
        t = head;
        head = head->next;
        free(t);
    }
}

template<typename T>
void myList<T>::traverseList()
{
    Node<T>* t = head;
    t = t->next;
    while(t != NULL)
    {
        printf("%d\t",t->data);
        t = t->next;
    }
    putchar(10);
}

template<typename T>
int myList<T>::lenList()
{
    int count = 0;
    Node<T>* t = head;
    t = t->next;
    while(t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

template<typename T>
void myList<T>::insertList(T data)
{
    Node<T>* cur = (Node<T>*)malloc(sizeof(Node<T>));
    if(NULL == cur)
    {
        printf("Insert failed.\n");
        return;
    }
    cur->data = data;
    cur->next = head->next;
    head->next = cur;
}

template<typename T>
Node<T> * myList<T>::searchList(T findData)
{
    Node<T>* t = head;
    t = t->next;
    while(t != NULL)
    {
        if(t->data == findData)
            break;
        t = t->next;
    }
    return t;
}

template<typename T>
void myList<T>::deleteNodeInList(Node<T> *pfind)
{
    Node<T>* t;
    t = pfind->next;
    pfind->data = t->data;
    pfind->next = t->next;
    free(t);
}

template<typename T>
void myList<T>::popSortList()
{
    Node<T> *pre,*p,*q;
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

template<typename T>
void myList<T>::reverseList()
{
    Node<T>* t;
    t = head->next;
    head->next = NULL;

    Node<T>* cur;
    while(t != NULL)
    {
        cur = t;
        t = t->next;
        cur->next = head->next;
        head->next = cur;
    }
}
