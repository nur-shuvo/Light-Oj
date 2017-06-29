#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 1000000000
#define pb push_back
using namespace std;
int r,c,cnt;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int vis[501][501],save[501][501];
char cell[501][501];
vector<pii>v;

int dfs(int x,int y)
{
	vis[x][y] = 1;
	v.pb(make_pair(x,y));
	if(cell[x][y]=='C') cnt++;

    for(int k=0;k<4;k++){
        int tx = x + fx[k];
        int ty = y + fy[k];
        if(tx>=1 && tx<=r && ty>=1 && ty<=c && cell[tx][ty]!='#'){
            if(vis[tx][ty]==0) dfs(tx,ty);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
    int q;
    scanf("%d %d %d",&r,&c,&q);
    getchar();
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) scanf("%c",&cell[i][j]);
        getchar();
    }
    printf("Case %d:\n",tt);
    memset(vis,0,sizeof(vis));

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cnt = 0;
            if(vis[i][j]==0 && cell[i][j]!='#') {
                    dfs(i,j);
                    for(int i=0;i<v.size();i++){
                        save[v[i].first][v[i].second] = cnt;
                    }
                    v.clear();
            }
        }
    }

    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",save[x][y]);
    }
   }
}
