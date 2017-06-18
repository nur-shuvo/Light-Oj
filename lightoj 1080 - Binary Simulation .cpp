#include<bits/stdc++.h>
#define LL long long
#define mx 100005
using namespace std;

char ss[100005];

struct info {
    LL prop, sum;
} tree[mx * 4];

void init(LL node, LL b, LL e)
{
    if (b == e) {
        tree[node].sum = 0;
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(LL node, LL b, LL e, LL i, LL j, LL x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) /* inside the range */
    {
        tree[node].sum += ((e - b + 1) * x);  /* e-b+1 nodes below,so e-b+1 times add x */
        tree[node].prop += x;  /* add x to the nodes below */
        return;
    }
    LL Left = node * 2;
    LL Right = (node * 2) + 1;
    LL mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    /* upore uthar somoy node gulo update hobe
       bam r dan paser sum cara-o jog hobe extra jog howa man */
}

LL query(LL node, LL b, LL e, LL i, LL j, LL carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);
        /* sum er sathe jog hobe sei range er sathe extra koto jog korte bolese seta */

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;

    LL p1 = query(Left, b, mid, i, j, carry + tree[node].prop); /* propagate value boye niye jacce carry variable */
    LL p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
int main()
{
    int t,m;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++){

        scanf("%s",ss);
        scanf("%d",&m);
        int n = strlen(ss);
        string s=".";
        s+=ss;

        for(int i=1;i<=n;i++)
            if(s[i]=='1')
            update(1,1,n,i,i,1);

        printf("Case %d:\n",tt);
        while(m--){
            getchar();
            char ch;
            scanf("%c",&ch);
            if(ch=='I')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b,1);
            }
            else
            {
                int a;
                scanf("%d",&a);
                printf("%d\n",query(1,1,n,a,a)%2);
            }
        }
   /*clear */
   for(int i=1;i<=n*4;i++) { tree[i].sum=0; tree[i].prop=0; }
   }
}
