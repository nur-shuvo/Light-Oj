#include<bits/stdc++.h>
#define mx 100005
#define LL long long
#define pb push_back
#define X first
#define Y second
#define pii pair<LL,LL>
using namespace std;
LL arr[mx],n;
vector< pii > tree(mx * 4);
pii boro = make_pair(123456789,0);
void init(LL node, LL b, LL e)
{
    if (b == e) {
        tree[node].X = arr[b];
        tree[node].Y = b; /** position **/
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if(tree[Left].X<tree[Right].X)  { tree[node].X = tree[Left].X;  tree[node].Y = tree[Left].Y; }
    else { tree[node].X = tree[Right].X;  tree[node].Y = tree[Right].Y; }

}

pii query(LL node, LL b, LL e, LL i, LL j)  /* takes O(logn) time */
{
    if (i > e || j < b)
        return boro; /* gone outside */
    if (b >= i && e <= j)
        return tree[node]; /* relevant segment */
    LL Left = node * 2;   /* should be divided more */
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    pii p1 = query(Left, b, mid, i, j);
    pii p2 = query(Right, mid + 1, e, i, j);

    if(p1.X<p2.X) return p1;
    else return p2;
}

LL area(LL b,LL e)
{
    if(b>e) return 0;
    if(b==e) return arr[b];

    LL minIdx = query(1,1,n,b,e).Y;

    LL ans = max(area(b,minIdx-1),area(minIdx+1,e));

    return max(ans,(e-b+1)*query(1,1,n,b,e).X);
}

int main()
{
    LL t; cin>>t;
    for(LL tt=1;tt<=t;tt++){
        cin >> n;
        for(LL i=1;i<=n;i++) scanf("%d",arr+i);
        init(1, 1, n);  /* build the tree */
        printf("Case %lld: %lld\n",tt,area(1,n));
    }
}
