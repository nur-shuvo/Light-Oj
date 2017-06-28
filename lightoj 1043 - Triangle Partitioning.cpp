/*
Solution idea :

    As ADE & ABC are sodrishkoni , so

    AD/AB = DE/BC
    ~~ AD = AB * (DE/BC)


    ADE / DEBC = r  (given)
    It can be written : ADE/(ADE+DEBC) = r/(1+r) ~~ ADE/(ADE+DEBC) = r/(1+r)
    By theorem of class 10 ( :P ) ,

    ADE/ABC = DE^2 / BC^2
    ~~ r/(1+r) =  DE^2 / BC^2
    ~~ DE/BC = sqrt(r/(1+r))
    ~~ DE/BC = x

    Finally, AD = AB*x

*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,test;
    double AB,BC,CA,AD,DE,r,x;
    cin>>test;
    for(i=1;i<=test;i++){
        cin>>AB>>CA>>BC>>r;
        x = sqrt(r/(r+1.0));
        AD = AB*x;
        printf("Case %d: %f\n",i,AD);
    }
    return 0;
}
