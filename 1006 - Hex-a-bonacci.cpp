#include<stdio.h>

long long dp[10005];
long long ff(long long n)
{
    if( n == 0 ) return dp[0];
    if( n == 1 ) return dp[1];
    if( n == 2 ) return dp[2];
    if( n == 3 ) return dp[3];
    if( n == 4 ) return dp[4];
    if( n == 5 ) return dp[5];

    if(dp[n]!=-1){
        return dp[n];
    }
    else {
       return dp[n] = ( ff(n-1) + ff(n-2) + ff(n-3) + ff(n-4) + ff(n-5) + ff(n-6) ) % 10000007;
    }
}

int main() {
    long long n,caseno = 0,cases;
    scanf("%lld",&cases);
    while( cases-- ) {
          for(long long i=0;i<10005;i++) dp[i]=-1;
          scanf("%lld%lld%lld%lld%lld%lld%lld",&dp[0],&dp[1],&dp[2],&dp[3],&dp[4],&dp[5],&n);
          ff(n);
          printf("Case %lld: %lld\n", ++caseno,dp[n]%10000007 );
    }
    return 0;
}
