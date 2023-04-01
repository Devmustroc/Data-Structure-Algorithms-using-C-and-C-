#include <stdio.h>


struct array {
    int A[20];
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

int main()
{
    struct array arr = {{1,2,3,4,5}, 20, 5};
    display(arr);
    return 0;
}