#include "sum.h"

int sum(int a[], int n)
{
    if (n == 0) //base case - if the array is empty, there is nothing to add
        return 0;
    else //recursive step
        return (a[n-1]+sum(a,n-1));
}