#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < m->length; i++)
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
    return max;
}

int Min(struct array m)
{
    int min = m.A[0];
    for (int i = 1; i < m.length; i++)
    {
        if (min > m.A[i])
        {
            min = m.A[i];
        }
    }
    return min;
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

float Avg(struct array m)
{
    return ((float)Sum(m) / m.length);
}

void _Resverse(struct array *m)
{
    int *B;
    int i, j;
    B = (int *)malloc(m->length*sizeof(int));

    for (i = m->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = m->A[i];
    }
    for (i = 0; i < m->length; i++)
    {
        m->A[i] = B[i];
    }
}

void _Reverse2(struct array *m)
{
    int i, j;
    for (i = 0, j = m->length - 1; i < j; i++, j--)
    {
        swap(&m->A[i], &m->A[j]);
    }
}

void InsertSort(struct array *m, int x)
{
    int i = m->length - 1;
    if (m->length == m->size)
    {
        return;
    }
    while(i >= 0 && m->A[i] > x)
    {
        m->A[i + 1] = m->A[i];
        i--;
    }
    m->A[i + 1] = x;
    m->length++;

}

int isSorted(struct array m)
{
    int i;
    for (i = 0; i <m.length - 1; i++)
    {
        if (m.A[i] > m.A[i + 1])
        {
            printf("Not sorted \n");
            return 0;
        }
    }
    printf("Sorted \n");
    return 1;
}

int main()
{
    struct array arr = {{1,2,10,2,15, 7}, 20, 6};
    display(arr);
    printf("%d \n", isSorted(arr));
    return 0;
}