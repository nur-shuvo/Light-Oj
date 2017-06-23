/*
How I have solved :
    1. Imagine the inputs as a directed graph . If the graph is not connected , then obviously output NO.
    2. First , find all the SCCs of the graph. Then consider the every SCC as node .
    3. If either of the nodes (SCC actually) has >=2 outgoing edges , then output NO for sure.
    4. Otherwise output YES.

If You have still confusion, how it works, then do some paperwork. And test some test cases . :)
*/


 #include<bits/stdc++.h>
 #define pb push_back
 using namespace std;
 stack <int> stk;
 vector<int>adj[10005],Radj[10005],component[10005];
// Radj means to reverse the edges of the graph
 int vis[10005],in_which[10005],mark,cnt;
 void dfs(int u)
 {
        vis[u] = 1;
        for(int i=0;i<adj[u].size();i++){
                 int v = adj[u][i];
                 if(vis[v]==0) dfs(v);
        }
        stk.push(u);
 }

void dfs2(int u,int mark)
{
           component[mark].pb(u);
           in_which[u] = mark;
           vis[u] = 1;

           for(int i=0;i<Radj[u].size();i++){
               int v = Radj[u][i];
               if(vis[v]==0) dfs2(v,mark);
           }
}

void Count(int u)
{
        vis[u] = 1;
        cnt++;
        for(int i=0;i<adj[u].size();i++){
                 int v = adj[u][i];
                 if(vis[v]==0) Count(v);
        }
}

int main()
{
         int t;
         scanf("%d",&t);
         for(int tt=1;tt<=t;tt++){

             for(int i=0;i<=10000;i++){ adj[i].clear(); Radj[i].clear(); component[i].clear(); }
             memset(vis,0,sizeof(vis));
             cnt = mark = 0;
             int child,e;
             scanf("%d",&child);
             map<int,int>mp;
             while(child--){
                 int e;
                 scanf("%d",&e);
                 for(int i=1;i<=e;i++){
                    int u,v;
                    scanf("%d %d",&u,&v);
                    adj[u].pb(v);
                    Radj[v].pb(u);
                    mp[u]=1,mp[v]=1;
                 }
             }
             printf("Case %d: ",tt);


    /* if the graph is not connected */
             Count(0);
             if(cnt!=mp.size()){
                printf("NO\n");
                continue;
             }


    //       topsort
             memset(vis,0,sizeof(vis));
             for(int i=0;i<1000;i++){
                if(vis[i]==0) dfs(i);
             }

            memset(vis,0,sizeof(vis));
            while (!stk.empty()){
                   int u = stk.top();
                   stk.pop();
                   if (vis[u]==0){
                        mark = mark+1;
                        dfs2(u,mark);
                  }
            }
            int ck = 1;
            for(int i=1;i<=mark;i++){
                int outgoing_edge = 0;
                for(int j=0;j<component[i].size();j++) {
                    int node = component[i][j];
                    for(int k=0;k<adj[node].size();k++){
                        if(in_which[adj[node][k]]!=i) outgoing_edge++;
                    }
                }
                if(outgoing_edge>=2){ printf("NO\n"); ck = 0 ; break; }
            }
            if(ck==1) printf("YES\n");
        }
}
//5
//3
//3 2
//2 0
//2 0
//3
//0 1
//0 2
//0 2
//2
//3 0
//0 3
//1
//3 1
//1
//0 1

