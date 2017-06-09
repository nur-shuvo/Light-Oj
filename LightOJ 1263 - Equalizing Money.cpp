#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define mx 10005
using namespace std;
int vis[mx+1],value[mx+1],sum,cnt;
vector<int>adj[mx+1];
void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    sum+= value[u];
    cnt++;
}
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",value+i);

    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int flag=1;
    int ck =0,eq;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            sum=cnt=0;
            dfs(i);
            if(ck==0){
                 if(sum%cnt!=0) { printf("Case %d: No\n",tt); flag=0; break; }
            }
            else{
                if(sum%cnt!=0) { printf("Case %d: No\n",tt); flag=0; break; }
                if(sum/cnt!=eq) { printf("Case %d: No\n",tt); flag=0; break; }
            }
            if(ck==0 && sum%cnt==0) { ck++; eq = sum/cnt; }
        }
    }
    if(flag) printf("Case %d: Yes\n",tt);
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof(vis));
    }
}
