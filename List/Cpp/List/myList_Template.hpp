#ifndef MYLIST_H
#define MYLIST_H

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template<typename T>
class myList
{
private:
    Node<T>* head;
public:
    myList();
    ~myList();
    void traverseList();
    int lenList();
    void insertList(T data);
    Node<T> * searchList(T findData);
    void deleteNodeInList(Node<T> *pfind);
    void popSortList();
    void reverseList();
};

#endif // MYLIST_H
