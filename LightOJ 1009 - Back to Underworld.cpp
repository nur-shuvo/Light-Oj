#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define inf 1000000000
#define mx 20005
using namespace std;

vector<int>adj[mx];
int dis[mx],color[mx];
LL bfs(int s)
{
    LL one,two; one = two = 0;
    queue<int>Q;
//    for(int i=1;i<mx;i++) dis[i] = inf; /* ensure it is very big  */

    Q.push(s);
    dis[s] = 0;
    color[s] = 1; one++;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
              int v = adj[u][i];
              if (dis[v] == inf){
                 if(color[u] == 1) { color[v] = 2; two++; }
                 else { color[v] = 1; one++; }
                 dis[v] = dis[u] + 1;
                 Q.push(v);
              }
        }
    }
    return max(one,two);
}

int ase[mx];

int main()
{
    int n,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    for(int i=1;i<mx;i++) dis[i] = inf;
    scanf("%d",&n);
    while(n--){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
        ase[u] = ase[v] = 1;
    }

    LL ans=0;

    for(int i=1;i<mx;i++){
        if(dis[i]==inf && ase[i]==1){
           ans += bfs(i);
        }
    }

    printf("Case %d: %lld\n",tt,ans);
    memset(color,0,sizeof(color));
    memset(ase,0,sizeof(ase));
    for(int i=1;i<mx;i++) adj[i].clear();

    }
}

