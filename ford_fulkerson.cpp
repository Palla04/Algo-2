#include<bits/stdc++.h>

using namespace std;
#define N 100

class Graph{
	public:
	
		int i;
		char color[10];
		int d[10];
		int c;
		queue<int> q;
		
		bool bfs(int G[100][100], int start, int t,int n,int p[])
		{
			for(i=0;i<n;i++)
			{
				color[i]='w';
				d[i]=0;
				p[i]=-1;
			}
			
			color[start]='g';
			d[start]=0;
			q.push(start);
			p[start] = -1;
			while(!q.empty())
			{
				c=q.front();
				cout <<c;
				q.pop();

				for(i=0;i<n;i++)
				{
					if(G[c][i] > 0 && color[i]=='w')
					{
						color[i]='g';
						p[i]=c;
						d[i]=d[c]+1;
						if(i==t)
						{
						    return true;							
						}
						else
						    q.push(i);
					}
					color[c]='b';
				}	
			}
			cout<<endl;
			return false;
			
		}
		int ford_fulkerson(int G[100][100],int start,int t,int n,int e)
		{
		    int u,v;
		    int r[100][100];
		    for (int u = 0; u < n;u++)
		    {
		       for(int v = 0; v < e;v++)
		       {
    		           r[u][v] = G[u][v];
		       }
		    }
		    
		    int p[n];
		    int m_f=0;
		    while(bfs(r,start,t,n,p))
		    {
		        int min_cap=INT_MAX;
                for (v = t; v != start; v = p[v]) {
	                u = p[v];
	                if(min_cap>r[u][v])
	                   min_cap=r[u][v];
		        }
		        for (v = t; v != start; v = p[v]) {
		            u = p[v];
		            r[u][v] -= min_cap;
		            r[v][u] += min_cap;
	            }

		        m_f += min_cap;
		    }
		    return m_f;
		}
};
int main()
{
	Graph h;
	int G[100][100];
	int n,e;
	int i,j,u,v,cost;
	int start,t;
	cout<<"enter the no of vertices & edge: ";
	cin>> n>> e;	
	for(i = 0; i<n; i++) {
        for( j=0; j<e; j++) {
            G[i][j] = 0;
        }
	}
	for(i=0;i<e;i++)
	{
		cout<<"Enter the graph: u v cost ";
		cin>>u>>v>>cost;
		
		 G[u][v]=cost;
	}
	cout<<"Enter the starting vertex: ";
	cin>>start;
	cout<<"Enter the ending vertex: ";
	cin>>t;
	cout << "The maximum flow: "<< h.ford_fulkerson(G,start,t,n,e);
	return 0;
}
