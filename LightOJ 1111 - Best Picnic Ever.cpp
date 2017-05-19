#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int vis[105][1005],live[105];
vector<int>adj[1005];
void dfs(int k,int u)
{
    vis[k][u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[k][v]) dfs(k,v);
    }
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
    int k,n,m;
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++) scanf("%d",live+i);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d %d",&u,&v);
        adj[u].pb(v);
    }
    for(int i=1;i<=k;i++){
        dfs(i,live[i]);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=1;j<=k;j++){
            if(!vis[j][i]){flag=1; break; }
        }
        if(!flag) ans++;
    }
    printf("Case %d: %d\n",t,ans);
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));
    }
}
