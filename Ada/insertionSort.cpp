/*a)Sort a given set of N integer elements using Insertion Sort technique and compute its time taken.*/
#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
  int i,j,item;
  for(i=0;i<n-1;i++){
    item = a[i];
    j = i-1;
    while(j>=0 && a[j]>item){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=item;
  }
}
      
int main(){
  int n,a[10000],i,j;
  cout<<"Enter the number of elements : ";
  cin>>n;
  cout<<"Enter the elements of array : "<<"\n";
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  selectionSort(a,n);
  cout<<"After Selection Sort : "<<"\n";
  for(j=0;j<n;j++){
    cout<<a[j]<<"\n";
  }
  return 0;
}
  
