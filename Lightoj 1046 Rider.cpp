#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define pb push_back
const int inf = 1e7;
using namespace std;
int r,c,Move;
//for knight moves
int fx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int fy[]= {-1,-2,-2,-1, 1,2, 2, 1};
int dis[11][11][11][11];
char cell[11][11];

int bfs(int x,int y)
{
    int xx = x, yy = y;

	for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) dis[xx][yy][i][j] = inf;
	dis[xx][yy][x][y] = 0;
	queue<pii>q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		for(int k=0;k<8;k++){
			int tx = top.X + fx[k];
			int ty = top.Y + fy[k];
			if(tx>=1 && tx<=r && ty>=1 && ty<=c && dis[xx][yy][tx][ty] == inf){
				dis[xx][yy][tx][ty] = dis[xx][yy][top.X][top.Y]  + 1;
				q.push(make_pair(tx,ty));
			}
		}
	}
}

int main()
{
   int t;
   cin>>t;
   for(int tt=1;tt<=t;tt++){
   scanf("%d%d",&r,&c);
   getchar();
   vector<pii>v;
   for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        scanf("%c",&cell[i][j]);
        if(cell[i][j]!='.'){
          bfs(i,j);
          v.pb(make_pair(i,j));
        }
    }
    getchar();
   }

   int ans = inf;

   for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        int total = 0;
        for(int k=0;k<v.size();k++){
            int ii,jj;
            ii = v[k].X; jj = v[k].Y;
            int K;
            K = cell[ii][jj] - 48;

            if(dis[ii][jj][i][j]==inf) Move  = inf;
            else if(dis[ii][jj][i][j]%K==0) Move = dis[ii][jj][i][j]/K;
            else Move = dis[ii][jj][i][j]/K + 1;

            total+= Move;
        }
        ans = min(ans,total);
    }
   }
   if(ans<inf)
   printf("Case %d: %d\n",tt,ans);
   else  printf("Case %d: %d\n",tt,-1);
   }
}

