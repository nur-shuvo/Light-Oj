/*
how to generate this formula :
    if n = 12,m = 3 , then
    initially a = 1; d = 1
    By our known formula in school we get , :P
    sum = - (m/2){ (2a) + (m-1)d} +  (m/2){ (2(a+m)) + (m-1)d} - (m/2){ (2(a+2m)) + (m-1)d} + (m/2){ (2(a+3m)) + (m-1)d}
        = (m/2)*(4*m)
        = (m/2)*(( n/m) * m) [ as n/m = 4 here
        = (n*m)/2
    You can do some paper work to prove for some other cases :)
*/

#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        LL n,m,ans;
        scanf("%lld %lld",&n,&m);

        ans = (n*m)/2;
        printf("Case %d: %lld\n",tt,ans);
    }
}
