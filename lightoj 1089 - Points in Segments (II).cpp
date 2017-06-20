//idea :
//You have to think about the amount of distinct numbers you have (at most: 2*50000 for the ranges, plus 50000 for the query
//points).For example, if I give you these ranges: [1,60000000],[40000000,90000000] and these query points: 1000000,50000000,
//100000000, then you can reduce the problem (without changing the final answer) to a smaller problem. In this case, the ranges
//become: [1,5],[3,6], and the query points become: 2,4,7. For "both problems", the answers are 1,2,0.

#include<bits/stdc++.h>

#define LL long long
#define mx 300000
#define pb push_back
using namespace std;

int f[300000],occu[300000];

int main()
{
    int n,q,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    scanf("%d %d",&n,&q);
    vector<int>v,query;
    vector< pair<int,int> > range;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        v.pb(l);
        v.pb(r);
        range.pb(make_pair(l,r));
    }
    for(int i=0;i<q;i++){
        int point;
        scanf("%d",&point);
        query.pb(point);
        v.pb(point);
    }
    sort(v.begin(),v.end());
    int ini = 1;
    for(int i=0;i<v.size();i++){
        if(mp.find(v[i])==mp.end()){
            mp[v[i]] = ini++;
        }
    }

    for(int i=0;i<n;i++){
        int l,r;
        l = mp[range[i].first];
        r = mp[range[i].second];


        f[l]++;
        f[++r]--;
    }

    int sum = 0;

    for(int i=1;i<mx;i++){
        sum+=f[i];
        occu[i] = sum;
    }
    printf("Case %d:\n",tt);
    for(int i=0;i<q;i++){
        int point;
        point = mp[query[i]];
        printf("%d\n",occu[point]);
    }
    memset(f,0,sizeof(f));
    memset(occu,0,sizeof(occu));

    }
}
