#include <stdio.h>

int * quickSort( int a[], int l, int r)
{int j;
    if( l < r ) 
     {   j = partition( a, l, r);
            quickSort( a, l, j-1);     
            quickSort( a, j+1, r);  
     }

return a; 
}

int partition( int a[], int l, int r) {
   int pivot, i, j, t; 
      pivot = a[l];   
      i = l; 
      j = r + 1;
	
   while(1)  
     {  do{ ++i;  }while(a[i] <= pivot && i <= r);	
        do{ --j;  }while(a[j] > pivot);
 
	 if( i >= j )    
		break;
        swap(&a[i], &a[j]);   
     }

    swap(&a[l], &a[j]);
  
  return j;
}

void swap(int *c, int *x) 
{    int tmp = 0;   
        tmp = *c;  
        *c = *x;        
       *x = tmp;
}

void main() 
{ int a[] = {7, 12, 1, -2, 0, 15, 4, 11, 9};
  int *s; 
  int n=sizeof(a)/4;
  s= quickSort(a, 0, n);

  printf("\n\nSorted array is:  "); 
   for(int i = 0; i < n; i++)   
        printf(" %d ", *(s+i));
}

