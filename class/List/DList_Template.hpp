//
//  DList.hpp
//  MyList
//  实现双向循环链表模板类，实现了简单的增(insert)、查(find)、删(delete)、遍历(traverse)、冒泡排序(popsort)（交换数据和交换结点两个版本）。
//  Created by Finy_Caniove on 2019/7/6.
//  Copyright © 2019 Finy_Caniove. All rights reserved.
//

#ifndef DList_hpp
#define DList_hpp

template<typename T>
struct Dnode
{
    T data;
    Dnode* pre;
    Dnode* next;
};

template<typename T>
class DList
{
private:
    Dnode<T>* head;
    
public:
    DList();
    void insert(T data);
    int len();
    void traverseNext();
    void traversePre();
    Dnode<T>* find(T data);
    void deleteMem(Dnode<T>* del);
    void popSortData();
    void popSortNode();
    ~DList();
    
};

#endif /* DList_hpp */
