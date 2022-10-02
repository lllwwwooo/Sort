#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
int  partition( ElemType *A, int i, int j)
{
   int low = i+1;
   int high = j;
   while (low<high)
   {
       while ((cmp(A+i, A+low)>=0) && low<=j)
       {
       	    low++;
       }
       while ((cmp(A+high, A+i)>=0)&& high>i)
       {
       	     high--;
       }
        if (low< high)
        {  Swap(A, low, high);}
    }
    if(cmp(A+high, A+i)<0)
    	Swap(A, i, high);
    return high;
}
void QuickSort(ElemType *A, int i, int j, int (*cmp)(ElemType *, ElemType *))
{
     if(j<=i)
     	return;
     int k=partition(A,i,j);
     QuickSort(A,i,k-1,cmp);
     QuickSort(A,k+1,j,cmp);
}
