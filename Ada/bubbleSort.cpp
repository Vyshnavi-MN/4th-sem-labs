#include<iostream>
#include<chrono>
using namespace std;

void bubbleSort(int a[] , int n){
	int temp=0 , i , j , k;
	for(i=0; i<n-1; i++){
		for(j=0;j<n-1-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void selectionSort(int a[] , int n){
	int temp=0 , i , j , k , min=0;
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[min]){
				temp = a[j];
				a[j] = a[min];
				a[min] = temp;
			}
		}
	}
	
	cout<<"After Selection Sort"<<endl;
	for(k=0;k<n;k++){
		cout<<a[k]<<"\t";
	}
	cout<<"\n";
}

int main(){
	clock_t start, end, start1 , end1;
	int n , ch;
	cout<<"Enter the number of elements in array : ";
	cin>>n;
	cout<<"Enter the elements to be sorted"<<endl;
	int a[100000] , i=0;
	for(i=n-1;i>=0;i--){
		a[i] = i;
	}
	while(1)
	{
		cout<<"1:Bubble Sort 2:Selection Sort 3:Exit"<<"\n"<<"Enter your choice: ";
		cin>>ch;
		if(ch==1){
			start = clock();
			bubbleSort(a , n);
			end = clock();
		}
		if(ch==2){
			start1 = clock();
			selectionSort(a , n);
			end1 = clock();
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
