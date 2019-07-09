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
