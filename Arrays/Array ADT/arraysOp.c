#include <stdlib.h>
#include <stdio.h>


struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("the elements of array are : \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}



int main ()
{
    struct Array arr;
    int i, n;

    printf("Enter the size of an Array: ");
    scanf("%d", &arr.size);

    arr.A =(int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter the number of numbers: ");
    scanf("%d", &n);

    printf("Enter all elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    display(arr);

    return 0;
}