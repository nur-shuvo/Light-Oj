#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){

    LL s,root,r,c,ind,f;
    cin>>s;
    printf("Case %d: ",tt);
    root = sqrt(s);

    if(root*root==s && root%2==1){
        printf("1 %d\n",root);
        continue;
    }
    if(root*root==s && root%2==0){
        printf("%d 1\n",root);
        continue;
    }

    if(root%2==0){
        r = root+1;
        ind = r*r;

        if(s>=ind-r+1){
            c = ind - s + 1;
        }

        else{
            c = root+1;
            LL Minus = ind - r + 1 - s;
            r-= Minus;

        }
        cout<<c<<" "<<r<<endl;
    }

    else{
        ind = (root+1)*(root+1);
        f = root+1;
        if(s>=ind-f+1){
            c = f;
            LL Plus = ind - s ;
            r = Plus + 1;
        }
        else{
            r = f;
            LL q = ind - f + 1 - s ;
            c = f - q;
        }
        cout<<c<<" "<<r<<endl;
    }
    }
}
