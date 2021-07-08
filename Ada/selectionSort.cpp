#include<iostream>
#include<chrono>
using namespace std;

void selectionSort(int a[] , int n){
	int temp=0,temp1=0,index=0, i , j , k ,l, min=0;
	for(i=0; i<n-1; i++){
		index=i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[index]){
				index=j;
			}
		}
		temp1=a[i];
		a[i]=a[index];
		a[index]=temp1;
		
	}
}

void countSort(int a[] ,int n){
	int temp=0,temp1=0,index=0, i , j , k ,l, min=0;
	cout<<"Enter k"<<endl;
	cin>>k;
	for(i=0; i<k; i++){
		index=i;
		for(j=i+1;j<n;j++){
			if(a[j] > a[index]){
				index=j;
			}
		}
		temp1=a[i];
		a[i]=a[index];
		a[index]=temp1;
		cout<<a[i]<<"\t";
	}
}


int main(){
	int n , ch , k , l , i;
	clock_t start, end;
	while(1)
	{
		cout<<"\n";
		cout<<"1:Selection Sort 2.Find k largest element 3:Exit"<<"\n"<<"Enter your choice: ";
		cin>>ch;
		if(ch==1){
			cout<<"Enter the number of elements in array : ";
			cin>>n;
			cout<<"Enter the elements to be sorted"<<endl;
			int a[100000] , j=0;
			for(i=n-1;i>=0;i--){
				a[j++]=i;
			}
			start = clock();
			selectionSort(a , n);
			end = clock();
			cout<<"After Selection Sort"<<endl;
			for(k=0;k<n;k++){
				cout<<a[k]<<"\t";
			}
		}
		if(ch==2){
			cout<<"Enter the number of elements in array : ";
			cin>>n;
			cout<<"Enter the elements to be sorted"<<endl;
			int a[100000];
			for(i=0;i<n;i++){
				a[i]=i;
			}
			countSort(a , n);
		}
		if(ch==3){
			exit(0);
		}
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    	cout << "Time taken by Bubble Sort is : " << fixed << time_taken; 
    	cout << " sec " << endl;
	}
	return 0;
}
