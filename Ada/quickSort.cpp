#include <iostream>

#include <bits/stdc++.h> 
using namespace std;

int partition(int arr[],int p,int r)
{
    
    int i,j,pivot,temp;
    i=p-1;
    pivot=arr[r];
    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}
void Quicksort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        Quicksort(arr,p,q-1);
        Quicksort(arr,q+1,r);
    }
}
void Grid(int n) 
{ 
    int arr[n][n]; 
  
    int x = 0; 
  
    for (int i = 0; i < n / 4; i++) { 
        for (int j = 0; j < n / 4; j++) { 
            for (int k = 0; k < 4; k++) { 
                for (int l = 0; l < 4; l++) { 
                    arr[i * 4 + k][j * 4 + l] = x; 
                    x++; 
                } 
            } 
        } 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            cout << arr[i][j] << " "; 
        } 
        
    } 
}
int main()
{
    int n;
     int ch;
	clock_t start, end; ;
	cout<<"enter 1 for quicksort 2:nxn ";
	cin>>ch;
	switch(ch)
	{
	   case 1:
        {        cout<<"enter size of array:";
              cin>>n;
             int arr[n];
             cout<<"enter the array elements:";
             for(int i=0;i<n;i++)
                 cin>>arr[i];
              start = clock(); 
              Quicksort(arr,0,n-1);
              end = clock();
   
            cout<<"sorted array:";
            for(int i=0;i<n;i++)
                   cout<<arr[i];
        break;
        }
     case 2:
    cin>>n;
  
    Grid(n); 
    break;
	}
  
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
     cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    
return 0;
  
}
