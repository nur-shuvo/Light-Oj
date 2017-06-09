//  * Prime Factorilization of a number
#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mx 10005
#define inf 1000000000
using namespace std;


vector<int>adj[mx];
int path[mx],dis[mx];

int bfs(int s,int des)
{
    queue<int>Q;
    for(LL i=1;i<mx;i++) dis[i] = inf; /* ensure it is very big  */

    Q.push(s);
    dis[s] = 0;
    while(!Q.empty()){
        int u = Q.front(),v;
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
              v = adj[u][i];
              if (dis[v] == inf){
                 dis[v] = dis[u] + 1;
                 path[v] = u;
                 Q.push(v);
                 if(v==des) break;
              }
        }
        if(v==des) break;
    }
}



void prime_factor(int n)
{
    int N = n;
    int prime[100];
    int i,j=0;
//    print the number of 2s that divide n
    if(n%2==0){
    while(n%2==0)
        n/=2;

        prime[j++]=2;
    }
//    n must be odd at this point . So we can skip one element ( i.e = i+=2)
    for(i=3;i*i<=n;i+=2){
        if(n%i==0){
        while(n%i==0)
            n/=i;
           prime[j++]=i;
        }
    }
     if(n>2 && n!=N)
        prime[j++]=n;

    for(i=0;i<j;i++){
        adj[N].pb(prime[i]+N);
//        cout<<n<<" "<<prime[i]+n<<endl;
    }
//    cout<<endl;
}


int main()
{
   /* pre-calculation */

   for(int i=3;i<=1000;i++){
      prime_factor(i);
   }

   int t; cin>>t;
   for(int tt=1;tt<=t;tt++){

   int st,des;
   scanf("%d %d",&st,&des);
   bfs(st,des);
   printf("Case %d: ",tt);
   if(dis[des]==inf) printf("-1\n");
   else printf("%d\n",dis[des]);
   }
}


