//
//  main.cpp
//  MyList
//
//  Created by Finy_Caniove on 2019/7/6.
//  Copyright © 2019 Finy_Caniove. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "DList_Template.hpp"
#include "DList_Template.cpp"
using namespace std;

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));
    DList<char> dl;
    int num;
    for (int i=0; i<10; i++)
    {
        num = 97+rand()%26;
        cout << num << '\t';
        dl.insert(num);
    }
    putchar(10);
    cout << "The length of Dlist is: " << dl.len() << endl;
    dl.traverseNext();
    dl.traversePre();
    if(dl.find(5))
    {
        cout << "Data Found!" << endl;
        cout << "After deleting:\n";
        dl.deleteMem(dl.find(5));
        dl.traverseNext();
    }
    else
        cout << "Data Not In DList!" << endl;
    
//    cout << "After sorting:\n";
//    dl.popSortData();
//    dl.traverseNext();
    
    cout << "After sorting:\n";
    dl.popSortNode();
    dl.traverseNext();
    dl.traversePre();
    
    return 0;
}
