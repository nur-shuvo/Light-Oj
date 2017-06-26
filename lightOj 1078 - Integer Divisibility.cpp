#include<bits/stdc++.h>
#define pb push_back
#define LL long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
    int n,allow;
    scanf("%d %d",&n,&allow);

    int res = 1;
    int cur = allow;

    while(1){

        if(cur%n==0) break;

        cur = cur * 10 + allow;

        cur = cur % n;

        res++;

    }
    printf("Case %d: %d\n",tt,res);

   }
}
