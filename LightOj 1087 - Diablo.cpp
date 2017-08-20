#include<bits/stdc++.h>
#define mx 200005
#define LL long long
#define pb push_back
int arr[mx],A[mx];
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

int query(int node, int b, int e, int i, int j)  /* takes O(logn) time */
{
    if (i > e || j < b)
        return 0; /* gone outside */
    if (b >= i && e <= j)
        return tree[node]; /* relevant segment */
    int Left = node * 2; /* should be divided more */
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)  /* takes O(logn) time */
{
    if (i > e || i < b)
        return; /* gone outside */
    if (b >= i && e <= i) { /* relevant segment */
        tree[node] = newvalue; /* update by new value */
        return;
    }
    int Left = node * 2; /* should be divided more */
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    int n,q,t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
    scanf("%d%d",&n,&q);
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++) { scanf("%d",&A[i]); arr[i] = 1; }
    getchar();
    int last = 2*n;
    init(1, 1, last);
    printf("Case %d:\n",tt);
    while(q--){
        char ch;
        ch = getchar();
        if(ch=='c'){
            int pos;
            scanf("%d",&pos); getchar();

            int lo = 1,hi = n,mid,ans=0;

            for(int step=1;step<=20;step++){
                mid = (lo+hi)/2;
                int j = query(1,1,last,1,mid);
                if(j>=pos){
                    hi = mid-1;
                    ans = mid;
                }
                else lo = mid+1;
            }
            if(ans) { printf("%d\n",A[ans]); update(1,1,last,ans,0); }
            else printf("none\n");
        }
        else{
            int value;
            scanf("%d",&value); getchar();
            n++;
            A[n] = value;
            update(1,1,last,n,1);
        }
    }
    }
}
