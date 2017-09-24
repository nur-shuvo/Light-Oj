#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    LL n,q,t;
    cin>>t;
    for(LL tt=1;tt<=t;tt++){
    printf("Case %lld:\n",tt);
    scanf("%lld %lld",&n,&q);

    LL ara[n+1];

    for(LL i=1;i<=n;i++)
        scanf("%lld",&ara[i]);

   map< pair<LL,LL>,LL >mp;
   LL k_ase[n+1];

   LL N = n;
   LL sum = 0;
   for(LL k=1;k<=n/2;k++){
     pair <LL,LL> p = make_pair(k,N);
     mp[p] = (N-k)*(ara[k]-ara[N]);
     sum+= mp[p];
     k_ase[k] = N;
     k_ase[N] = k;

     N--;
   }

   LL case_1 = ara[1];
   while(q--){
    LL ck;
    scanf("%lld",&ck);
    if(ck==0){
        LL ind,val;
        scanf("%lld %lld",&ind,&val);
        ind++;

        if(n==1)  continue;

        if(n%2==1 && ind==(n/2)+1){
            continue;
        }

        LL ind2 = k_ase[ind];
        ara[ind] = val;

        if(ind2<ind){
            LL save = mp[make_pair(ind2,ind)];
            sum-= save;
            LL xx = (ind-ind2)*(ara[ind2]-ara[ind]);
            sum+= xx;
            mp[make_pair(ind2,ind)] = xx;
        }
        else{
            LL save = mp[make_pair(ind,ind2)];
            sum-= save;
            LL xx = (ind2-ind)*(ara[ind]-ara[ind2]);
            sum+= xx;
            mp[make_pair(ind,ind2)] = xx;
        }
    }
    else{
        if(n==1) printf("0\n",case_1);
        else{
            printf("%lld\n",sum);
        }
    }
   }
  }
}
