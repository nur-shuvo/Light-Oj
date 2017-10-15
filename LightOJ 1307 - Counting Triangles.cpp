#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,a,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++) { cin>>a; v.pb(a); }

    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j){
                int a = v[i];
                int b = v[j];
                int way = (lower_bound(v.begin()+j+1,v.end(),a+b)-v.begin()-(j+1));
                ans+= way;
            }
        }
    }
    printf("Case %d: %d\n",tt,ans);
    }
}
