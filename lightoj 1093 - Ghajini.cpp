#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx * 4],tree1[mx*4];
//..............for range minimum
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if(tree[Left]<tree[Right]) tree[node] = tree[Left];
    else tree[node] = tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return mx;  /*ei segment e ekta boro num return korey dilam jehetu relevant na  */
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    if(p1<p2) return p1;
    else return p2;
}

//..............for range maximum

void init1(int node, int b, int e)
{
    if (b == e) {
        tree1[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init1(Left, b, mid);
    init1(Right, mid + 1, e);
    if(tree1[Left]>tree1[Right]) tree1[node] = tree1[Left];
    else tree1[node] = tree1[Right];
}

int query1(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return -1;  /*ei segment e ekta coto num return korey dilam jehetu relevant na  */
    if (b >= i && e <= j)
        return tree1[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query1(Left, b, mid, i, j);
    int p2 = query1(Right, mid + 1, e, i, j);
    if(p1>p2) return p1;
    else return p2;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int t_case=1; t_case<=t; t_case++){
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    if(d==1) { printf("Case %d: %d\n",t_case,0); continue; } /* corner case */
    init(1,1,n);
    init1(1,1,n);

    int ans = 0;
    for(int i=1;i+d-1<=n;i++){
        int Min = query(1,1,n,i,i+d-1);
        int Max = query1(1,1,n,i,i+d-1);
        int dif = abs(Max-Min);
        ans = max(ans,dif);
    }
    printf("Case %d: %d\n",t_case,ans);

    }
}

