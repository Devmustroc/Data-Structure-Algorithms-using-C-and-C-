#include <stdio.h>
/**
* Simple recursion
*/

void recu(int m)
{
    if (m > 0)
    {
        // Head Recursion
        recu(m - 1);
        printf("%d", m);
    }
}

int main()
{
    int m = 5;
    recu(m);
    return 0;
}