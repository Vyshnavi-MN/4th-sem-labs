#include<bits/stdc++.h> 
using namespace std; 
int first(int arr[], int low, int high, int x, int n) 
{ 
    if(high >= low) 
    { 
        //int mid = low + (high - low)/2; or
        int mid = (low + high)/2;
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid; 
        else if(x > arr[mid]) 
            return first(arr, (mid + 1), high, x, n); 
        else
            return first(arr, low, (mid -1), x, n); 
    } 
    return -1; 
} 

int main() 
{ 
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8} , f , l , i; 
    int n = sizeof(arr)/sizeof(int); 
    int x = 10;
    f =  first(arr, 0, n-1, x, n);
    /*l = last(arr, 0, n-1, x, n);*/
    if(f == -1){
      cout<<"-1 -1 0"<<"\n";
    }
    else{
      cout<<"First Occurrence at index = "<< f;
      i=f;
      while(arr[i]<=x)
      {
        i++; 
      }
      cout<<"\t"<<"Last Occurrence at index = "<<i-1;
      cout<<"\t"<<"Count = "<<(i - f)<<"\n"; 
    }
    return 0; 
} 
