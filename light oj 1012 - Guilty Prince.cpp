// ...    for king's moves direction array will be
// ...    int fx[]={1,-1,0,0};
// ...    int fy[]={0,0,1,-1};


#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 1000000000
using namespace std;
int r;
int c;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

//int fx[]={1,-1,0,0,1,-1,1,-1};
//int fy[]={0,0,1,-1,1,-1,-1,1};
int dis[50][50],cell[50][50];

int bfs(int x,int y)
{
	for(int i=1;i<=r;i++) for(int j =1;j<=c;j++) dis[i][j] = inf;
	dis[x][y] = 0;
	queue<pii>q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		for(int k=0;k<4;k++)
		{
			int tx = top.X + fx[k];
			int ty = top.Y + fy[k];
			if(tx>=1 && tx<=r && ty>=1 && ty<=c && dis[tx][ty] == inf && cell[tx][ty]!=1)
			{
				dis[tx][ty] = dis[top.X][top.Y] + 1;
				q.push(make_pair(tx,ty));
			}
		}
	}
}

int main()
{
    int T,strtx,strty;
    char ch;
    cin>>T;
    for(int t=1;t<=T;t++){
    cin>>c>>r;

    memset(cell,0,sizeof(cell));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>ch;
            if(ch=='#') cell[i][j]=1;
            if(ch=='@') strtx=i,strty=j;
        }
    }

    bfs(strtx,strty);
    int ans = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
         if(dis[i][j]!=inf) ans++;
        }
    }
    printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

