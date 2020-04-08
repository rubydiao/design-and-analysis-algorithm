#include<stdio.h>
 
int binary_search(int arr[], int n, int k) 
{ int l = 0, r = (n-1);
 
  while(l <= r)
    {  int mid = (l + r) /2;   
       if (arr[mid] == k)        
            return mid;
       if (arr[mid] < k)     
            l = mid + 1;   
       else                 
            r = mid - 1;
    }
    
    return -1;
}

int interpolationSearch(int arr[], int n, int k)
{  int l = 0, r = (n - 1);
 
 while (l <= r)
  {  int mid = l + (((double)(r-l) /(arr[r]-arr[l]))*(k - arr[l]));
     if (arr[mid] == k)
          return mid;
     if (arr[mid] < k)       
         l = mid + 1;
     else                   
         r = mid - 1;
  }

    return -1;
}



int main()
{

 int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
 int n = sizeof(arr)/sizeof(arr[0]);
 int x = 18; 
 
 // int index = binary_search(arr, n, x);
 int index = interpolationSearch(arr, n, x);
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found.");
    
 return 0;

}