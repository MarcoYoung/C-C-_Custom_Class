//
//  mylist.h
//  MyList
//  实现单向链表类，实现了简单的增(insert)、查(find)、删(delete)、遍历(traverse)、冒泡排序(popsort)、逆转(reverse)、销毁(destroy)。
//  Created by Finy_Caniove on 2019/7/9.
//  Copyright © 2019 Finy_Caniove. All rights reserved.
//
#ifndef MYLIST_H
#define MYLIST_H

typedef struct _Node
{
    int data;
    struct _Node* next;
}Node;

Node * createList();
void traverseList(Node *head);
int lenList(Node *head);
void insertList(Node * head, int data);
Node * searchList(Node * head,int findData);
void deleteNodeInList(Node *pfind);
void popSortList(Node *head);
void destroyList(Node *head);
void reverseList(Node *head);

#endif // MYLIST_H
