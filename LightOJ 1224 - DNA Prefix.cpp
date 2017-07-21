#include<bits/stdc++.h>
using namespace std;
#define MAX_node 1000000
#define MAX_LEN 50
#define pb push_back
int tree[MAX_node][4],repeat_prefix[MAX_node][4];
int root,nnode,res,ans=-1,ch;
void initialization(){
    root = 0;
    nnode = 0;
    for(int i=0;i<4;i++) tree[root][i] = -1;
}
void insert(string S){
    int len = S.size();
    int now = root;
    for(int i=0;i<len;i++){
        if(S[i]=='A') ch = 0; if(S[i]=='C') ch = 1; if(S[i]=='G') ch = 2; if(S[i]=='T') ch = 3;
            if(tree[now][ch]==-1){
                tree[now][ch] = ++nnode;
            }
            for(int j=0;j<4;j++) tree[nnode][j] = -1;
            repeat_prefix[now][ch]++;
            now = tree[now][ch];
    }
}

void query(string S){
    int len = S.size();
    int now = root;
    for(int i=0;i<len;i++){
        if(S[i]=='A') ch = 0; if(S[i]=='C') ch = 1; if(S[i]=='G') ch = 2; if(S[i]=='T') ch = 3;
        res = repeat_prefix[now][ch] * (i+1);
        ans = max(ans,res);
        now = tree[now][ch];
    }
}

int main()
{
    int n,t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    string str; ans=-1;
    memset(repeat_prefix,0,sizeof(repeat_prefix));
    cin>>n;
    vector<string>v;
    initialization();
    while(n--){
    cin>>str;
    insert(str);
    v.pb(str);
    }
    for(int i=0;i<v.size();i++){
        query(v[i]);
    }
    printf("Case %d: %d\n",tt,ans);
    }
}
