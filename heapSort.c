#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
void  Max_Heapify(ElemType *A, int start, int end, int (*cmp)(ElemType *, ElemType *))
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        if (son + 1 <= end && (cmp(A+son+1, A+son)>0))
            son++;
        if ( (cmp(A+dad, A+son)>0))
            return;
        else
        {
            Swap(A,dad,son);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void HeapSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *))
{
    for(int i= n/2-1; i>=0; i--)
        Max_Heapify(A, i, n-1, cmp);
    for(int i=n-1; i>0; i--)
    {
        Swap(A, 0, i);
        Max_Heapify(A, 0, i-1, cmp);
    }
}
