#ifndef MYLIST_H
#define MYLIST_H

typedef struct _Node
{
    int data;
    struct _Node* next;
}Node;

class myList
{
private:
    Node* head;
public:
    myList();
    ~myList();
    void traverseList();
    int lenList();
    void insertList(int data);
    Node * searchList(int findData);
    void deleteNodeInList(Node *pfind);
    void popSortList();
    void reverseList();
};

#endif // MYLIST_H
