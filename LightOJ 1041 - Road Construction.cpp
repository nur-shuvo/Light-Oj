#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define fast ios::sync_with_stdio(false)
using namespace std;

int parent[200000];
int Size[200000]; /* size[i] = s where i is the representative of the set  */

void makeset(int x)
{
    parent[x]=x;
    Size[x]=1;
}
int Find(int x)
{
    while(x!=parent[x]){
        x = parent[x];
    }
    return x; /* x means representative */
}
void Union_by_size(int x,int y)
{
    int r = Find(x);
    int s = Find(y);
    if(r==s) return;
    else if(Size[r]>Size[s]){
        parent[s] = r;
        Size[r]+=Size[s];
    }
    else{
        parent[r] = s;
        Size[s]+= Size[r];
    }
}

int main()
{
//    fast;
    int n,w,t,m;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    cin>>m;
    vector< pair<int,pair<int,int> > >Edges;
    int as = 0;
    map<string,int>mp;
    while(m--){
        string u,v;
        cin>>u>>v>>w;
        if(mp.find(u)==mp.end()) mp[u] = as++;
        if(mp.find(v)==mp.end()) mp[v] = as++;
        Edges.pb(make_pair(w,make_pair(mp[u],mp[v])));
    }

    sort(Edges.begin(),Edges.end());
    int e = 0;
    int minCost = 0;
    n = as;
    for(int i=0;i<=n;i++) makeset(i);

    for(int i=0;i<Edges.size();i++){
        int W = Edges[i].first;
        int U = Edges[i].second.first;
        int V = Edges[i].second.second;

        if(Find(U)!=Find(V)){
            minCost+= W;
            Union_by_size(U,V);
            e++;
            if(e==mp.size()-1) break;
        }
    }
    printf("Case %d: ",tt);
    if(e==mp.size()-1) cout<<minCost<<endl;
    else cout<<"Impossible\n";
    }
}
