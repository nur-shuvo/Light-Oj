#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

//for directed acyclic graph (DAG)
//slightly modified bfs (topological sort)
//you can print the sort in increasing or decreasing order
//based on modified bfs

vi ts,adj[100000];
int indegree[10000];
int main()
{
        int T;
        cin>>T;
        for(int tt=1;tt<=T;tt++){

        memset(indegree,0,sizeof(indegree));
        int ck=1;

        int m;
        cin>>m; getchar();
        map<string,int>mp;
        int as = 1;
        for(int i=0;i<m;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end()) mp[s1]=as++;
            if(mp.find(s2)==mp.end()) mp[s2]=as++;
            adj[mp[s1]].pb(mp[s2]);
            indegree[mp[s2]]++;
        }


//        main part , run kahn's algo like bfs
        priority_queue<int, vector<int>,greater<int> > pq;  /* min pq nilam karon holo smallest to
        largest node precedence problem staement e , dorkar porle maximum pq nite hobe */

        for(int i=1;i<as;i++){
            if(indegree[i]==0) pq.push(i);
        }
        vector<int>ts;

        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ts.push_back(u);
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                indegree[v]--;
                if(indegree[v]==0 )
                    pq.push(v);
            }
        }
        /* queue khali howar por o jodi kono node er in degree 0 na thake tahole
        graph e cycle ase */

        for(int i=1;i<as;i++) if(indegree[i]!=0) ck=0;
        if(ck==0) printf("Case %d: No\n",tt);
        else printf("Case %d: Yes\n",tt);
        for(int i=1;i<as;i++) adj[i].clear();
        }
        return 0;
}

