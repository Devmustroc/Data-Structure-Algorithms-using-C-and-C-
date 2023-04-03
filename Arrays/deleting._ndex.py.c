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

void Insert(struct array *m, int index, int x) {
    int i;
    if (index >= 0 && index <= m->length)
    {
        for (i = m->length; i > index; i--)
        {
            m->A[i] = m->A[i - 1];
        }
        m->A[index] = x;
        m->length++;
    }
}

int Delete(struct array *m, int index)
{
    int x = 0;
    if (index >= 0 && index <= m->length)
    {
        x = m->A[index];
        for (int i = index; i < m->length - 1; i++) {
            m->A[i] = m->A[i + 1];
        }
        m->length--;
        return x;
        }
    return 0;
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
    display(arr);
    Insert(&arr, 2, 20);
    display(arr);
    Append(&arr, 10);
    display(arr);
    Delete(&arr, 2);
    display(arr);

    return 0;
}