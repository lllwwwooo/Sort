#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"
void MergeSort(ElemType *A, int i,int j, int (*cmp)(ElemType *, ElemType *))
{
    if(j<=i)
        return;
    int k=(i+j)/2;
    MergeSort(A,i,k,cmp);
    MergeSort(A,k+1,j,cmp);
    int l=i,h=k+1,t=0;
    ElemType *B = (ElemType*) malloc((j-i+1)*sizeof(ElemType));
    while(l<=k&&h<=j)
    {
        if(cmp(A+h,A+l)>0)
        {
            B[t]=A[l];
            l++;
            t++;
        }
        else
        {
            B[t]=A[h];
            h++;
            t++;
        }

    }
    if(l<=k)
        memcpy(B+t, A+l, (k-l+1)*sizeof(ElemType));
    if(h<=j)
        memcpy(B+t, A+h, (j-h+1)*sizeof(ElemType));
    memcpy(A+i, B, (j-i+1)*sizeof(ElemType));
    free(B);
}
