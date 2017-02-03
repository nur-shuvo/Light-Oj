#include<bits/stdc++.h>
#define mx 100001
int arr[mx];
int tree[mx * 4];
using namespace std;

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
    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

void add(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] += newvalue ;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    add(Left, b, mid, i, newvalue);
    add(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
    printf("Case %d:\n",k);
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    for(int i=0;i<q;i++){
        int u;
        scanf("%d",&u);
        if(u==1){
            int i;
            scanf("%d",&i);
            printf("%d\n",query(1,1,n,i+1,i+1) );
            update(1,1,n,i+1,0);
        }
        if(u==2){
            int i,v;
            scanf("%d %d",&i,&v);
            add(1,1,n,i+1,v);
        }
        if(u==3){
            int i,j;
            scanf("%d %d",&i,&j);
            printf("%d\n",query(1,1,n,i+1,j+1) );
        }
    }
    }
    return 0;
}

