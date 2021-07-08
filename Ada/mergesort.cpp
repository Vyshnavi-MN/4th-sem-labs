#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
void merge(int arr[],int p,int q,int r)
{
    int len1=q-p+1;
    int len2=r-q,k,i,j;
    int left[len1],right[len2];
    for(i=0;i<len1;i++)
        left[i]=arr[p+i];
    for(j=0;j<len2;j++)
        right[j]=arr[q+1+j];
    i=0;j=0;k=p;
    while(i<len1 && j<len2)
    {
    if(left[i]<=right[j])
    {
        arr[k]=left[i];
        i++;k++;
    }
    else
    {
        arr[k]=right[j];
        j++;k++;
    }
    }
     while (i < len1) 
    { 
        arr[k] = left[i]; 
        i++; 
        k++; 
    } 
  
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        j++; 
        k++; 
    } 
}
void mergesort(int arr[],int p,int r)
{
    if(p<r)
    {   int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main()
{   int n;

     int ch;
	clock_t start, end; ;
    cout<<"enter th size";
    cin>>n;
    int arr[n];
    cout<<"elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    start = clock(); 
         mergesort(arr,0,n-1);
              end = clock();
    cout<<"sorted array:";
    for(int i=0;i<n;i++)
        cout<<arr[i];
   int m=(0+n-1)/2;
    if(n%2!=0)
    cout<<"median"<<arr[m];
    else
    cout<<"median"<<(arr[m]+arr[m+1])/2;
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
     cout << "Time taken for performing mergesort is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
}
