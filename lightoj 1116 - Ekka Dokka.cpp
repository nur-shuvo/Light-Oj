#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    LL w,n,m=1,ww;
    scanf("%lld",&w);
    if(w%2==1){
      printf("Case %d: Impossible\n",tt,n,m);
      continue;
    }
    ww = w;
    while(w%2==0){
        w/=2;
        m*=2;
    }
    n = ww/m;
    printf("Case %d: %lld %lld\n",tt,n,m);

    }

}
