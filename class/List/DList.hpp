//
//  DList.hpp
//  MyList
//
//  Created by Finy_Caniove on 2019/7/6.
//  Copyright © 2019 Finy_Caniove. All rights reserved.
//

#ifndef DList_hpp
#define DList_hpp

struct Dnode
{
    int data;
    Dnode* pre;
    Dnode* next;
};

class DList
{
private:
    Dnode* head;
    static int num;
    
public:
    DList();
    void insert(int data);
    int len();
    void traverseNext();
    void traversePre();
    Dnode* find(int data);
    void deleteMem(Dnode* del);
    void popSortData();
    void popSortNode();
    ~DList();
    
};

#endif /* DList_hpp */
