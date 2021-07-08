
/* Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm. */

#include<bits/stdc++.h>
using namespace std;

int a[30][30],visited[30],n,totwt=0,c=0;

void prim(int v)
{
	
	int indi,indj;	
	visited[v]=1;
	int min=10000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(visited[i]==1 && visited[j]==0)
			{
				if(a[i][j]<min)
				{
					min=a[i][j];
					indi=i;
					indj=j;
				}
			}
		}
	}
	
	totwt=totwt+a[indi][indj];
	cout<<indi<<" to "<<indj<<"\t "<<a[indi][indj]<<endl;
	c++;
	visited[indj]=1;
	if(c==n-1)
		return;
	prim(indj);
}

int main()
{
	
	cout<<"Enter the no. of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter the weighted matrix ( enter 9999 for infinity)"<<endl;
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			
		}
	}
	cout<<"Minimum spanning tree is"<<endl;
	cout<<"Edges \t Weights"<<endl;
	prim(1);
	cout<<"Minimum cost = "<<totwt<<endl;
	return 0;
}

/* output
Enter the no. of vertices
6
Enter the weighted matrix ( enter 9999 for infinity)
0 30 10 9999 9999 9999
30 0 9999 20 20 25
10 9999 0 9999 15 9999
9999 20 9999 0 15 10
9999 20 15 15 0 35
9999 25 9999 10 35 0
Minimum spanning tree is
Edges 	 Weights
1 to 3	 10
3 to 5	 15
5 to 4	 15
4 to 6	 10
4 to 2	 20
Minimum cost = 70
*/	

	
