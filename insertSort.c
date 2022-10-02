#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void InsertSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *))
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        while((j>=0)&&(cmp(A+j,A+j+1)>0))
        {
             Swap(A,j+1,j);
             j--;
        }
    }
}
