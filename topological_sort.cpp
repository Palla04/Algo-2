#include <iostream>
#include<stack>
using namespace std;

class Graph
{
    public:
    int G[10][10];
    int n,e ;
    char color[10];
    int p[10],time=0,F[10],D[10];
    int start;
    stack<int> s;
    
  void DFS_Visit(int u)
  {
    
    int i;
    color[u]='g';
    D[u]=time++;
    printf("\nVisited: %d", u);
    for(i=1;i<=n;i++)
    {
        if(G[u][i]==1 && color[i]=='w')
        {
            p[i]=u;
            DFS_Visit(i);
        }
    }
    F[u]==time++;
    color[u]='b';
    s.push(u);
  }

  void DFS()
  {
    int i;
    for (i = 1; i <= n; i++)
    {
        color[i] = 'w';
        p[i] = 0;
    }
    
    // Start DFS from the specified starting vertex
    DFS_Visit(start);
    
    for (i = 1; i <= n; i++)
    {
        if (color[i] == 'w')
            DFS_Visit(i);
    }

    printf("\nThe topological sort: ");
    while (!s.empty())
    {
        int p = s.top();
        s.pop();
        printf("%d ", p);
    }
 }

};

int main() {
    Graph h;
    int i,j,u,v;
    printf("Enter the no of vertices: ");
    scanf("%d", &h.n);
    printf("Enter the no of edge: ");
    scanf("%d", &h.e);
    
    for(i=1;i<=h.n;i++)
    {
        for(i=1;i<=h.e;i++)
        {
            h.G[i][i]=0;
        }
    }
    
    for(i=1;i<=h.e;i++)
    {
        printf("Enter the graph: u v: ");
        scanf("%d %d",&u ,&v );
        
        h.G[u][v]=1;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &h.start);
    h.DFS();
    
    
    return 0;
}
