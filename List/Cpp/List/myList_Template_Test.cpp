#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylist.h"
#include "mylist.cpp"

int main()
{
    myList<int> ls;
    srand(time(NULL));
    int num;

    for(int i=0; i<10; i++)
    {
        num = rand()%20;
        ls.insertList(num);
    }

    cout << "Original list:" << endl;
    ls.traverseList();
    cout << "After sorting:" << endl;
    ls.popSortList();
    ls.traverseList();
    printf("Search target 5: ");
    Node<int>* fd = ls.searchList(5);
    if(fd == NULL)
        printf("Not Found.\n");
    else
    {
        printf("Have Found. Deleting...\n");
        ls.deleteNodeInList(fd);
        ls.traverseList();
    }

    printf("After reversing:\n");
    ls.reverseList();
    ls.traverseList();

    printf("Test over! Destroying list...\n");
    return 0;
}

