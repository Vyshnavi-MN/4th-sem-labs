/*a) From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra’s algorithm.*/
#include<iostream>
using namespace std;
#define INFINITY 999
int n 0;
int min_Dist(int dist[], bool visited[] )   
{
	int min=INFINITY,index;                 
	for(int v=1;v<=n;v++)
	{
		if(visited[v]==false &&dist[v]<=min)      
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void Dijkstra(int cost[n][n],int src)
{
	int dist[n];                             
	bool visited[n];
	for(int i=1;i<=n;i++)                   
	{
		dist[i]=INFINITY;
		visited[i]=false;	
	}
	dist[src]=0;                                   
	for(int c=2;c<=V;c++)                           
	{
		
		int u=min_Dist(dist,visited);            
		visited[u]=true;                         
		for(int v=1;v<=V;v++)                    

		{
			if(!visited[v] && cost[u][v] &&dist[u]+cost[u][v]<dist[v])
			dist[v]=dist[u]+cost[u][v];
		}
	}
	 
	cout<<"The shortest path  "<<src<<" to all the other vertices is: \n";
	for(int i=1;i<=V;i++)                      
	{
	   if(i!=src)
	   cout<<"source:"<<src<<"\t destination:"<<i<<"\t MinCost is:"<<dist[i]<<"\n";
	}
}
int main()
{
  int n=0;
	int i,j, s;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  int cost[n][n]
	cout<<"\n Enter the cost matrix weights:\n";
	for(i=1;i<=n;i++)     
          for(j=1;j<=V;j++)
          {
              cin>>cost[i][j];
			//Absence of edge between vertices i and j is represented by INFINITY
             if(cost[i][j]==0)     
               cost[i][j]=INFINITY;    
           }
cout<<"\n Enter the Source Vertex: "; 
cin>>s;

	Dijkstra(cost,s,n);
	return 0;	
}
/*Output
Enter the number of vertices: 5
Enter the cost matrix weights:
0 10 999 5 999
999 0 1 2 999
999 999 0 999 4
999 3 9 0 2
7 999 6 999 0
Enter the Source Vertex: 1
The shortest path  1 to all the other vertices is: 
source:1	 destination:2	 MinCost is:8
source:1	 destination:3	 MinCost is:9
source:1	 destination:4	 MinCost is:5
source:1	 destination:5	 MinCost is:7
*/
