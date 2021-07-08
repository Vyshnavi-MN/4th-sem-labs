//Implement All Pair Shortest paths problem using Floyd’s algorithm.

#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
void floyd(int a[][20])
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
		}
	}
}

int main()
{
	
	cout<<"Enter the no. of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter the weighted matrix ( enter 99999 for infinity)"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			
		}
	}
	floyd(a);
	cout<<"All Pair Shortest paths :"<<endl;
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
/* output
1.Enter the no. of vertices
4
Enter the weighted matrix ( enter 99999 for infinity)
8 6 99999 10
99999 0 3 7
5 4 0 1
7 2 99999 0
All Pair Shortest paths :
8 6 9 10 
8 0 3 4 
5 3 0 1 
7 2 5 0 
2.Enter the no. of vertices
4
Enter the weighted matrix ( enter 99999 for infinity)
0 5 99999 10
99999 0 3 99999
99999 99999 0 1
99999 99999 99999 0
All Pair Shortest paths :
0 5 8 9 
99999 0 3 4 
99999 99999 0 1 
99999 99999 99999 0 
*/
