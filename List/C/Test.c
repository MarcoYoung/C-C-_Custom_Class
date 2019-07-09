#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylist.h"

int main()
{
    Node* ls = createList();
    srand(time(NULL));
    int num;

    for(int i=0; i<10; i++)
    {
        num = rand()%20;
        insertList(ls,num);
    }

    printf("Original list:\n");
    traverseList(ls);
    printf("After sorting:\n");
    popSortList(ls);
    traverseList(ls);
    printf("Search target 5: ");
    Node* fd = searchList(ls,5);
    if(fd == NULL)
        printf("Not Found.\n");
    else
    {
        printf("Have Found. Deleting...\n");
        deleteNodeInList(fd);
        traverseList(ls);
    }

    printf("After reversing:\n");
    reverseList(ls);
    traverseList(ls);

    printf("Test over! Destroying list...\n");
    destroyList(ls);

    return 0;
}
