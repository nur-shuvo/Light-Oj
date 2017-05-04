#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector <int>adj[50005];
int c,vis[50005],flag[50005];

int dfs(int start)
{
   if(vis[start]==1) return 0;
   vis[start] = 1;
   c++;
   for(int i=0;i<adj[start].size();i++){
     int v = adj[start][i];
         if(vis[v]==0){
             dfs(v);
         }
   }
    vis[start] = 0;
    flag[start]++;
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    memset(flag,0,sizeof(flag));
    memset(vis,0,sizeof(vis));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb(v);
    }
    int mini = 0,ans;
    for(int i=1;i<=n;i++){
        c=0;
        if(flag[i]==0){
        dfs(i);
        if(c>mini){
            mini = c;
            ans = i;
        }
        else if(c==mini){
            ans = min(ans,i);
        }
        }
    }
    printf("Case %d: %d\n",tt,ans);
    for(int i=1;i<=n;i++) adj[i].clear();
    }
    return 0;
}
