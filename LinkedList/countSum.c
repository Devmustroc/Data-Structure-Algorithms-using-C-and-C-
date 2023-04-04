#include <stdio.h>
#include <stdlib.h>

struct  Node {
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct  Node *)malloc(sizeof (struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n ; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;

    }
}

int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

void Display(struct Node *p)
{
    for(p = first; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

int RecursiveCount(struct Node *p)
{
    if (p!= NULL)
    {
        return RecursiveCount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int Sum(struct Node *p)
{
    int s = 0;
    while(p)
    {
        s += p->data;
        p= p->next;
    }
    return s;
}

int RecursiveSum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return RecursiveSum(p->next) + p->data;
    }
}


int main()
{
    int A[] = {3,5,7,10,15,8,12,20, 25};
    Create(A, 8 + 1);
    Display(first);
    printf("Length is %d \n", count(first));
    printf("Length is %d \n", RecursiveCount(first));
    printf("Sum is %d \n", Sum(first));
    printf("Sum is %d \n", RecursiveSum(first));
    return 0;
}