#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL check(LL  n)
{
    LL count = 0;
    for (LL i=5; n/i>=1; i *= 5)
          count += n/i;

    return count;
}
int main()
{
    int t;
    LL ans;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int q;
        scanf("%d",&q);
        printf("Case %d: ",tt);
        LL lo = 1,hi = 1e18,mid,chk=0;

        for(int step=1;step<=100;step++){
            mid=(lo+hi)/2;
            if(check(mid)==q){ ans=mid; chk = 1; hi = mid-1; }
            else if(check(mid)<q) lo = mid+1;
            else hi = mid-1;
        }
        if(chk==0) printf("impossible\n");
        else printf("%lld\n",ans);
    }
}
