#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

//for directed acyclic graph (DAG)
//slightly modified dfs (topological sort)
int ck;
vi ts,adj[100000];
int vis[100000];
void dfs2(int u)
{
    vis[u] = 1;
    for(int j=0;j<adj[u].size();j++){
        int v = adj[u][j];
        if(vis[v]==0) dfs2(v);
    }
    if(ck==1)
    ts.pb(u);  /* this is the only change */
}
int main()
{
    int T,N,M,u,v;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        ck=1;
        ts.clear();
        memset(vis,0,sizeof(vis));

        int ans=0;
        scanf("%d %d",&N,&M);
        for(int j=1;j<=M;j++){
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
        }

        for(int i=1;i<=N;i++){
            if(vis[i]==0) dfs2(i);
        }
        ck=0;
        memset(vis,0,sizeof(vis));

        for(int i=ts.size()-1;i>=0;i--){
            int node  = ts[i];
            if(vis[node]==0){
                dfs2(node);
                ans++;
            }
        }
        printf("Case %d: %d\n",i,ans);
        for(int i=1;i<=N;i++) adj[i].clear();
    }
    return 0;
}
