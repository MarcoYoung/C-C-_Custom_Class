//
//  DList.cpp
//  MyList
//
//  Created by Finy_Caniove on 2019/7/6.
//  Copyright © 2019 Finy_Caniove. All rights reserved.
//
#include <iostream>
using namespace std;
#include "DList.hpp"

template<typename T>
DList<T>::DList()
{
    head = new Dnode<T>;
    head->next = head;
    head->pre = head;
}

template<typename T>
void DList<T>::insert(T data)
{
    Dnode<T>* cur = new Dnode<T>;
    cur->data = data;
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;
    cur->next->pre = cur;
}

template<typename T>
int DList<T>::len()
{
    Dnode<T>* t = head->next;
    int count = 0;
    while(t != head)
    {
        count++;
        t = t->next;
    }
    return count;
}

template<typename T>
void DList<T>::traverseNext()
{
    Dnode<T>* t = head->next;
    while(t != head)
    {
        cout << t->data << '\t';
        t = t->next;
    }
    putchar(10);
}

template<typename T>
void DList<T>::traversePre()
{
    Dnode<T>* t = head->pre;
    while(t != head)
    {
        cout << t->data << '\t';
        t = t->pre;
    }
    putchar(10);
}

template<typename T>
Dnode<T>* DList<T>::find(T data)
{
    Dnode<T>* t = head->next;
    while(t != head)
    {
        if(t->data == data)
            return t;
        t = t->next;
    }
    return nullptr;
}

template<typename T>
void DList<T>::deleteMem(Dnode<T>* del)
{
    del->next->pre = del->pre;
    del->pre->next = del->next;
    delete del;
}

template<typename T>
void DList<T>::popSortData()
{
    int length = len();
    Dnode<T> *p,*q;
    for(int i=0; i<length-1; i++)
    {
        p = head->next;
        q = p->next;
        for(int j=0; j<length-1-i; j++)
        {
            if(p->data > q->data)
                swap(p->data, q->data);
            p = q;
            q = p->next;
        }
    }
}

template<typename T>
void DList<T>::popSortNode()
{
    int length = len();
    Dnode<T> *pre, *p, *q;
    for(int i=0; i<length-1; i++)
    {
        pre = head;
        p = head->next;
        q = p->next;
        for(int j=0; j<length-1-i; j++)
        {
            if(p->data > q->data)
            {
                p->next = q->next;
                q->next->pre = p;
                pre->next = q;
                q->pre = pre;
                p->pre = q;
                q->next = p;
                
                swap(p,q);
            }
            pre = p;
            p = q;
            q = q->next;
        }
    }
}

template<typename T>
DList<T>::~DList()
{
    Dnode<T>* t = head->next;
    Dnode<T>* del;
    while(t != head)
    {
        del = t;
        t = t->next;
        delete del;
    }
        
    delete head;
}
