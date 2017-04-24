#include<bits/stdc++.h>
#define LL long long
#define N 105
using namespace std;
#define inf 1000000000000000
LL mat[2*N+1][2*N+1];
LL dp[2*N+1][2*N+1];
LL r,c,n;
LL call(LL i, LL j)
{
    if (i >= 0 && i < r and j >= 0 and j < c)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        LL ret = -inf;
        if(i>=n-1){
            ret = max(ret, call(i + 1, j - 1) + mat[i][j]);
            ret = max(ret, call(i + 1, j) + mat[i][j]);
        }
        else{
        ret = max(ret, call(i + 1, j) + mat[i][j]);
        ret = max(ret, call(i + 1, j + 1) + mat[i][j]);
        }


        return dp[i][j] = ret;
    }
    else
        return 0;
}
int main()
{
    LL t;
    scanf("%lld",&t);
    for(LL tt=1;tt<=t;tt++){
    memset(dp, -1,sizeof(dp));
    memset(mat, 0 ,sizeof(mat));

    scanf("%lld",&n);
    r = c = 2*n-1;

    for(LL i=0;i<n;i++){
        for(LL j=0;j<=i;j++){
            scanf("%lld",&mat[i][j]);
        }
    }

    LL p = n-2;
    for(LL i=n;i<2*n - 1;i++){
        for(LL j=0;j<=p;j++){
            scanf("%lld",&mat[i][j]);
        }
        p--;
    }
    LL dd = call(0,0);
    printf("Case %lld: %lld\n",tt,dd);
    }

    return 0;
}
