/*Implement Warshall’s algorithm using dynamic programming.*/

#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
void warshall(int a[][20])
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				a[i][j]=a[i][j] || (a[i][k]&&a[k][j]);
		}
	}
}

int main()
{
	
	cout<<"Enter the no. of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			
		}
	}
	warshall(a);
	cout<<"The Transitive closure is"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
			
		}
		cout<<"\n";
	}
	return 0;
}

/* 0utput
1. Enter the no. of vertices
4
Enter the adjacency matrix
1 0 1 0
0 1 0 0
1 0 1 1
0 1 1 1
The Transitive closure is
1 1 1 1 
0 1 0 0 
1 1 1 1 
1 1 1 1 
2. Enter the no. of vertices
4
Enter the adjacency matrix
1 1 0 1
0 1 1 0
0 0 1 1
0 0 0 1
The Transitive closure is
1 1 1 1 
0 1 1 1 
0 0 1 1 
0 0 0 1 
*/
