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

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int Linear_Search(struct array *m, int key)
{
    for (int i = 0; i < m->length; i ++)
    {
        if (key == m->A[i])
        {
            // transposition
            // swap(&m->A[i], &m->A[i-1]);
            // move to head
            swap(&m->A[i], &m->A[0]);
            printf("Element found at index %d \n", i);
            return i;
        }
    }
    printf("Element not found \n");
    return -1;
}
int BinarySearch(struct array m, int key)
{
    int low = 0, height = m.length, mid;
    while(low <= height)
    {
        mid = (low + height) / 2;
        if (key == m.A[mid])
            return mid;
        else if (key < m.A[mid])
            height = mid + 1;
        else
            low = mid + 1;
    }
    return -1;
}
// Binary Search recursively
int recursiveBinarySearch(int arr[], int key, int low, int height)
{
    int mid;
    if (low <= height)
    {
        mid = (low + height) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return recursiveBinarySearch(arr, key, low, mid - 1);
        else
            return recursiveBinarySearch(arr, key, mid + 1, height);
    }
    return -1;
}

int Get(struct array m, int index)
{
    if (index >= 0 && index < m.length)

    {
        return m.A[index];
    }
    return -1;
}

void Set(struct array *m, int index, int x)
{
    if (index >= 0 && index < m->length)
    {
        m->A[index] = x;
    }
}

int Max(struct array m)
{
    int max = 0;
    for (int i = 0; i < m.length; i++) {
        if (max < m.A[i]) {
            max = m.A[i];
        }
    }
}

int Sum(struct array m)
{
    int total = 0;
    for (int i = 0; i < m.length; i++)
    {
        total += m.A[i];
    }
    return total;
}
int RecursiveSum(struct array m, int n)
{
    if (n < 0)
    {
        return 0;
    }
    else {
        return RecursiveSum(m, n - 1) + m.A[n];
    }
}

int main()
{
    struct array arr = {{8,25,2,5,3,10,0, 50,49,30,52}, 20, 11};
    display(arr);
    printf("%d \n",Get(arr, 3));
    Set(&arr, 3, 10);
    display(arr);
    printf("%d \n", Sum(arr));
    printf("%d \n", RecursiveSum(arr, arr.length));
    printf("%d \n", Max(arr));




    return 0;
}