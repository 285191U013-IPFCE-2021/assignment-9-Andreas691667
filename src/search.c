#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{
    if (n==0) //base case 1: The array is empty, i.e. there are no values to search for
    return false;

    else if (n>0 && a[n-1]==x) //base case 2: The first element in the array is the value for which is searched
        return true;

    else //recursive step
        return search(a, n-1,x); 
}