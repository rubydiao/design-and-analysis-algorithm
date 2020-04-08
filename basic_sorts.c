#include <stdio.h>

int * bubble_sort(int A[], int n)
{ int i, j, tmp;
   for(i=0;i<n;i++)
     { for(j=0;j<n-1;j++)
         if(A[j] > A[j+1])
           {  tmp = A[j];
              A[j] = A[j+1];
             A[j+1] = tmp;
          }
     }
     return A;
}

int * selection_sort(int A[], int n)
    { int i, j, min, tmp;
       for(i=0; i<n-1; i++)
         { min = i;
           for(j=i+1; j<n; j++)
              if(A[j] < A[min])
                    min = j;
           tmp = A[i];
           A[i] = A[min];
           A[min] = tmp;
         }
     return A;
    }
   
int * insertion_sort(int A[], int n)
{ int i, j,v;
   for(i=1; i<=n-1; i++)
      { v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v)
            { A[j+1] = A[j];
              j = j-1;
            }
        A[j+1] = v;
       }
    return A;
}

int main()
{ int A[] = {8,7,9,4,22,1,2};
  int i, j,v , n = sizeof(A)/4;
  int *B;
 
  //B = selection_sort(&A, n);
 //  B = bubble_sort(&A, n);
  B = insertion_sort(&A, n);    
 
   for(i=0; i < n ; i++)
      printf("%d ", *(B+i));
     
    return 0;
}