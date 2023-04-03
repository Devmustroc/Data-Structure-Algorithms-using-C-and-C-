#include <stdio.h>

struct Array {
    int A[5];
    int length;
    int size;
};

void Display(struct Array m) {
    for (int i = 0; i <= m.length - 1; i++)
    {
        printf("%d: %d \n", i, m.A[i]);
    }
    printf("\n");
}

void Append(struct Array *m, int x)
{
    if (m->length < m->size)
    {
        m->A[m->length++] = x;
    }
}

int Deleting(struct Array *m, int index)
{
    if (index > 0 && index < m->length)
    {
         int x = m->A[index];
        for (int i = index; i < m->length - 1; i++)
        {
            m->A[i] = m->A[i + 1];
        }
        m->length--;
        return x;
    }
    return 0;
}

void Insert(struct Array *m, int idx, int x)
{
    if (idx >= 0 && idx < m->length)
    {
        for (int i = m->length ; i > idx; i--)
        {
            m->A[i] = m->A[i - 1];
        }
        m->A[idx] = x;
        m->length++;
    }
}

void swap(int *m, int *n)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;
}

int Linear_Search(struct Array *m, int key)
{
    for (int i = 0; i < m->length; i++)
    {
        if (key == m->A[i])
        {
            // transposition
            swap(&m->A[i], &m->A[i-1]);
            // move to head
            // swap(&m->A[i], &m->A[0]);
            printf("Element found at index %d \n", i);
            return i;
        }
    }
    printf("Element not found \n");
    return -1;
}
 int BinarySearch(struct Array m, int key)
 {
    int low = 0, height = m.length, mid;
    while(low <= height)
    {
        mid = (low + height) / 2;
        if (key == m.A[mid])
            return mid;
        else if (key < m.A[mid])
            height = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
 }


int recursiveBinarySearch(int arr[], int key, int low, int height)
{
    if (low <= height)
    {
        int mid = (low + height) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return recursiveBinarySearch(arr, key, low, mid - 1);
        else
            return recursiveBinarySearch(arr, key, mid + 1, height);
    }
    return -1;
}

int main()
{
    struct Array arr = {{1,2,3,4,5}, 5, 5};
    Display(arr);
    Linear_Search(&arr, 2);
    Display(arr);
    printf("%d \n", BinarySearch(arr, 2));
    Display(arr);
    printf("%d \n", recursiveBinarySearch(arr.A, 3, 0, arr.length));
    Display(arr);
}