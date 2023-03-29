#include <stdio.h>
#include <stdlib.h>

struct  node {
    int data;
    struct node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct node *t, *last;

    first = (struct  node *)malloc(sizeof (struct node));
    first->data = A[0];
    first->next = NULl;
    last = first;

    for (i = 1; i < n ; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;

    }
}

int main(int argc, char *argv[])
{
    int A[] = {3,5,7,10,15};
    return;
}




