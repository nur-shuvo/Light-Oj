/* How I have solved :

    First save the shortest distances of all nodes from both start and des point in two arrays dis1,dis2 and
    ans : max(dis1[i]+dis2[i]),0<=i<n
*/


#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define inf 1000000000
#define mx 200005
using namespace std;
// we keep all distance of nodes from source node in dis array
vector<int>adj[mx];
int path[mx],dis1[mx],dis2[mx];

void CLEAR(int n)
{
    for(int i=0;i<n;i++) adj[i].clear();
}
int bfs(int s,int cur)
{
    queue<int>Q;
    for(LL i=0;i<mx;i++) if(cur==1) dis1[i] = inf; else dis2[i] = inf;

    Q.push(s);
    if(cur==1)
    dis1[s] = 0;
    else dis2[s]=0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
              int v = adj[u][i];
              if(cur==1){
              if (dis1[v] == inf){
                 dis1[v] = dis1[u] + 1;
                 path[v] = u;
                 Q.push(v);
              }
              }
              else{
                 if (dis2[v] == inf){
                 dis2[v] = dis2[u] + 1;
                 path[v] = u;
                 Q.push(v);
              }
              }
        }
    }
}

int main()
{
   int n,m,t;
   cin>>t;
   for(int tt=1;tt<=t;tt++){
   scanf("%d%d",&n,&m);
   while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    adj[u].pb(v);
    adj[v].pb(u);
   }
   int start,des,ans=0;
   scanf("%d%d",&start,&des);
   bfs(start,1);
   bfs(des,2);
   for(int i=0;i<n;i++) ans = max(ans,dis1[i]+dis2[i]);
   printf("Case %d: %d\n",tt,ans);
   CLEAR(n);
   }
}
