//observation 1 : As it is an weighted tree, this following bfs is applicable for finding distances between source
//node to any node .
//
//observation 2 : First run a bfs on any node,say bfs(0), and find the node p which has the largest distance .and p
//would be one of the desired farthest nodes.
//
//observation 3. Then, run bfs(p) and Find the largest distance from p . And that's the answer .

#include<bits/stdc++.h>
#define pb push_back
#define inf 1000000000
using namespace std;
vector<int>adj[30000];

int n,visited[30000];
int dis[30000];
vector<int>Cost[30000];
// This bfs is okay when to Find distance from any source node For a undirected acyclic weighted tree.
void bfs(int s)
{
    for(int i=0;i<n;i++) { visited[i]=0; dis[i]=inf; }
    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    dis[s] = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(visited[v]==0){
                visited[v] = 1;
                dis[v] = dis[u] + Cost[u][i];
                Q.push(v);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int u,v,cost;
            scanf("%d %d %d",&u,&v,&cost);
            adj[u].pb(v);
            adj[v].pb(u);

            Cost[u].pb(cost);
            Cost[v].pb(cost);
        }
        bfs(0);
        int max_dis=0,strt;
        for(int i=0;i<n;i++){
            if(dis[i]>max_dis){strt=i; max_dis=dis[i]; }
        }

        bfs(strt);

        max_dis=0;
        for(int i=0;i<n;i++){
            if(dis[i]>max_dis){ max_dis=dis[i]; max_dis=dis[i]; }
        }
       printf("Case %d: %d\n",tt,max_dis);
       for(int i=0;i<n;i++){adj[i].clear(); Cost[i].clear(); }
    }
}
