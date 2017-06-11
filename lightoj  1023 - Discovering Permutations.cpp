#include<bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    char alpha[27];
    int n,k,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    scanf("%d %d",&n,&k);
    int i,b = 65;
    for(i=0;i<n;i++) alpha[i] = b++;

    printf("Case %d:\n",tt);
    int cnt=0;
    do{
      for(int i=0;i<n;i++) printf("%c",alpha[i]);
      printf("\n");
      cnt++;
      if(cnt==k) break;
    }while(next_permutation(alpha,alpha+n));

    }

}
