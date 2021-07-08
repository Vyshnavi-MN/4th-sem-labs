#include<iostream>
using namespace std;


int getPos(int a[], int n, int mobile){
	int i,pos=0;
	for(i=0;i<n;i++){
		if(a[i]==mobile){
			pos=i+1;
		}
	}
	return pos;
}

int getMobile(int a[], bool dir[], int n){
	int mobile = 0 , prev_mobile = 0;
	for(int i=0 ; i<n ; i++){
		if(dir[i]==false && i!=0){
			if(a[i]>a[i-1] && a[i]>prev_mobile){
				mobile=a[i];
				prev_mobile=mobile;
			}
		}
		
		if(dir[i]==true && i!=n-1){
			if(a[i]>a[i+1] && a[i]>prev_mobile){
				mobile=a[i];
				prev_mobile=mobile;
			}
		}
	}
	
	if(mobile==0 && prev_mobile==0){
		return 0;
	}
	else{
		return mobile;
	}
}

int fact(int n){
	int i,res=1;
	for(i=1;i<=n;i++){
		res=res*i;
	}
	return res;
}

void getOnePerm(int a[] , bool dir[] , int n){
	int temp=0,temp1=0 , mobile , pos;
	mobile = getMobile(a,dir,n);
	pos = getPos(a,n,mobile);
	if(dir[a[pos-1]]==false && a[pos-1]>a[pos-2]){
		temp=a[pos-2];
		a[pos-2]=a[pos-1];
		a[pos-1]=temp;
	}		
	if(dir[a[pos-1]]==true && a[pos-1]>a[pos]){
		temp1=a[pos];
		a[pos]=a[pos-1];
		a[pos-1]=temp;
	}
	for(int i=0;i<n;i++){
		if(a[i]>mobile){
			if(dir[a[i]-1]==false){
				dir[a[i]-1]==true;
			}
			else if(dir[a[i]-1]==true){
				dir[a[i]-1]==false;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<a[i];
	}	
	cout<<endl;
}

void getPermutations(int n){
	int a[n],i;
	bool dir[n];
	for(i=0;i<n;i++){
		dir[i]=false;
	}
	for(i=0;i<n;i++){
		a[i]=i+1;
		cout<<a[i];
	}
	cout<<endl;
	for(i=1;i<fact(n);i++){
		getOnePerm(a,dir,n);
	}
}

int main(){
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	getPermutations(n);
	return 0;
}

	
