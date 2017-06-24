// solved

 /* How I have solved :

    It's a really classical graph problem.

1 . Run algorithm like Tarjan-SCC algorithm to find all SCCs. Consider each SCC as a new vertices, link a edge between these new vertices according to the origin graph, we can get a new graph. Obviously, the new graph is a Directed Acyclic Graph(DAG).
2 . In the DAG, find all vertices whose in-degree is 0, we define them {X}; find all vertices whose out-degree is 0, we define them {Y}.
3 . If DAG has only one vertices, the answer is 0; otherwise, the answer is max(|X|, |Y|).
*/
 #include<bits/stdc++.h>
 #define pb push_back
 using namespace std;
 stack <int> stk;
 vector<int>adj[20005],Radj[20005],component[20005];
 int indegree[20005],outdegree[20005];
// Radj means to reverse the edges of the graph
 int vis[20005],in_which[20005],mark,cnt;
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

             cnt = mark = 0;
             int n,e;
             scanf("%d %d",&n,&e);

             while(e--){
                 int u,v;
                 scanf("%d%d",&u,&v);
                 adj[u].pb(v);
                 Radj[v].pb(u);
             }
             printf("Case %d: ",tt);

    //       topsort
             memset(vis,0,sizeof(vis));
             for(int i=1;i<=n;i++){
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

            for(int i=1;i<=mark;i++){
                set <int> S;
                for(int j=0;j<component[i].size();j++) {
                    int node = component[i][j];
                    for(int k=0;k<adj[node].size();k++){
                        if(in_which[adj[node][k]]!=i) {
                            int q = in_which[adj[node][k]];
                            S.insert(q);
                        }
                    }
                }
                outdegree[i]+= S.size();
                set<int> :: iterator it;
                for(it = S.begin();it!=S.end();it++) indegree[*it]++;
            }

            int X,Y;
            X = Y = 0;
            for(int i=1;i<=mark;i++) {
                if(indegree[i]==0)  X++;
                if(outdegree[i]==0) Y++;
            }

             cnt = max(X,Y);
             if(n==1 || mark ==1 ) cnt = 0;
             printf("%d\n",cnt);
             /* clear part */
             for(int i=1;i<=n;i++){ adj[i].clear(); Radj[i].clear(); component[i].clear(); }
             memset(vis,0,sizeof(vis));
             memset(indegree,0,sizeof(indegree));
             memset(outdegree,0,sizeof(outdegree));
        }
}
