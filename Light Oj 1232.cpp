#include<bits/stdc++.h>
using namespace std;

int coin[55];  //value of coins available
int n,make,ret1,ret2;  //we will try to make 18
int dp[55][1001],c[55];
int mod = 1e8 + 7;
int call(int i,int amount)
{
    if(i>=n) { //All coins have been taken
        if(amount==make) return 1;
        else return 0;
    }

    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    int tt=0;

    for(int j=1;j<=c[i];j++){
    if(amount + coin[i]*j <=make ) tt += call(i+1,amount + coin[i]*j)% mod;
    else break;
    }

    tt += call(i+1,amount) % mod;

    return dp[i][amount] = (tt) % mod; //storing and returning.

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;cc++){
    scanf("%d %d",&n,&make);
    for(int i=0;i<n;i++) scanf("%d",&coin[i]);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    memset(dp,-1,sizeof(dp));
    printf("Case %d: %d\n",cc,call(0,0));
    }
    return 0;
}



