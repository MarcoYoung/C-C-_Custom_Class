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

DList::DList()
{
    head = new Dnode;
    head->next = head;
    head->pre = head;
}

void DList::insert(int data)
{
    Dnode* cur = new Dnode;
    cur->data = data;
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;
    cur->next->pre = cur;
}

int DList::len()
{
    Dnode* t = head->next;
    int count = 0;
    while(t != head)
    {
        count++;
        t = t->next;
    }
    return count;
}

void DList::traverseNext()
{
    Dnode* t = head->next;
    while(t != head)
    {
        cout << t->data << '\t';
        t = t->next;
    }
    putchar(10);
}

void DList::traversePre()
{
    Dnode* t = head->pre;
    while(t != head)
    {
        cout << t->data << '\t';
        t = t->pre;
    }
    putchar(10);
}

Dnode* DList::find(int data)
{
    Dnode* t = head->next;
    while(t != head)
    {
        if(t->data == data)
            return t;
        t = t->next;
    }
    return nullptr;
}

void DList::deleteMem(Dnode* del)
{
    del->next->pre = del->pre;
    del->pre->next = del->next;
    delete del;
}

void DList::popSortData()
{
    int length = len();
    Dnode *p,*q;
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

void DList::popSortNode()
{
    int length = len();
    Dnode *pre, *p, *q;
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

DList::~DList()
{
    Dnode* t = head->next;
    Dnode* del;
    while(t != head)
    {
        del = t;
        t = t->next;
        delete del;
    }
        
    delete head;
}
