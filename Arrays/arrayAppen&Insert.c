#include <stdio.h>


struct array {
    int A[10];
    int size;
    int length;
};

void display(struct array m){
    int i;
    printf("the elements of the array are: \n");
    for (i = 0; i < m.length; i++)
    {
        printf("%d ", m.A[i]);
    }
    printf("\n");
}

void Append(struct array *m, int x){
    if (m->length < m->size)
    {
        m->A[m->length++] = x;
    }
}

int main()
{
    struct array arr = {{1,2,3,4,5}, 10, 5};
    Append(arr, 10);
    display(arr);
    return 0;
}