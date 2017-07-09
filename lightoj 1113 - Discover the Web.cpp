#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t; getchar();
    for(int tt=1;tt<=t;tt++){
    printf("Case %d:\n",tt);
    stack <string>for_ward,back_ward;

    string cur = "http://www.lightoj.com/";
    back_ward.push(cur);
    while(1){
    string s,web;
    cin>>s;
    if(s=="QUIT") break;
    if(s=="VISIT"){
        cin>>web;
        back_ward.push(cur);
        cur = web;
        while(!for_ward.empty()){
            for_ward.pop();
        }
    }
    else{
        if(s=="BACK"){
            if(back_ward.size()==1) { printf("Ignored\n"); continue; }
            else{
                for_ward.push(cur);
                cur = back_ward.top();
                back_ward.pop();
            }
        }
        else{
            if(for_ward.empty()) { printf("Ignored\n"); continue; }
            else{
                back_ward.push(cur);
                cur = for_ward.top();
                for_ward.pop();
            }
        }
    }
    cout<<cur<<endl;
    }
    }
}
