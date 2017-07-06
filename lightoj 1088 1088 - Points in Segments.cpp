#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int mx = 0;
int Count[500005];
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    map<int,int>mp,mp2;
    int n,q,a,l,r;
    scanf("%d%d",&n,&q);
    int ara[n+5];
    vector<int>v,input;
    vector< pair<int,int> > query;
    for(int i=1;i<=n;i++) { scanf("%d",&a); v.pb(a); mx = max(mx,a); }
    input = v;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        v.pb(l);
        v.pb(r);
        query.pb(make_pair(l,r));
        mx = max(mx,l);
        mx = max(mx,r);
    }

    sort(v.begin(),v.end());

    int as = 1;
    for(int i=0;i<v.size();i++) mp[v[i]] = as++;

    for(int i=0;i<input.size();i++){
        mp2[mp[input[i]]]=1;
    }
    int input_last = mp[input[input.size()-1]];
    int sum = 0;
    for(int i=1;i<=as;i++){
        if(i>input_last) Count[i] = sum;
        else if(mp2.find(i)!=mp2.end()){
            sum++;
            Count[i] = sum;
        }
        else Count[i] = Count[i-1];
    }

    printf("Case %d:\n",tt);
    for(int i=0;i<query.size();i++){
        int L = mp[query[i].first];
        int R = mp[query[i].second];
        printf("%d\n",Count[R]-Count[L-1]);
    }
    memset(Count,0,sizeof(Count));
    }
}
