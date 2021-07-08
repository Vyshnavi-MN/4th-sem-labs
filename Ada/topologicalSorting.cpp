#include<bits/stdc++.h> 
using namespace std; 
   
class Graph 
{ 
    int V;    
    list<int> *adj; 
    public:
    void topologicalMain(int v, bool visited[],stack<int> &s); 

    Graph(int V); 
  
    void addEdge(int v, int w); 
  
    void topological(int v); 
    void lexicographically_Smallest();
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);  
} 
  
void Graph::topologicalMain(int v, bool visited[],stack<int> &s) 
{ 
    
    visited[v] = true; 
    
  
    
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalMain(*i, visited,s); 
    s.push(v);
} 
  
 
void Graph::topological(int v) 
{ 
    stack<int> s ;
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    
    
    
    topologicalMain(v, visited,s); 
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        cout<<a;
    }
} 
void Graph::lexicographically_Smallest()
{   
    int min=V,c=0,arr[V],k=0;
    int *indegree=new int[V];
    for(int i=0;i<V;i++)    indegree[i]=0;
    list<int>::iterator i;
    for(int j=0;j<V;j++)
    {
        for (i = adj[j].begin(); i != adj[j].end(); ++i) 
        {   indegree[*i]++;
        }
    }
    for(int p=0;p<V;p++)
    {
    for(int u=0;u<V;u++)
    {
        if(indegree[u]==0 && u<min)
            min=u;
            
    }
    if(min!=V)c++;
    arr[k]=min;k++;
    indegree[min]=V;
    for(i=adj[min].begin();i!=adj[min].end();i++)
        indegree[*i]--;
    min=V;
    }
    if(c==V)
        for(int j=0;j<k;j++)
         cout<<arr[j];
    else
        cout<<"-1";
    
}

  
 
int main() 
{ 
  int ch;
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    while(1)
    {   
        cout<<"1:Topologcal ordering of vertices"<<endl;
        cout<<"2:Lexicographically Smallest Topological Ordering"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            g.topological(0);
                break;
            case 2:
                g.lexicographically_Smallest();
                break;
        }
    }

   
   
  
    return 0; 
} 
