/**
For case 2 7 , output would be 8 . See the chess board below :

............    * * 0 0 * * 0  ..........
............    * * 0 0 * * 0  ..........

A (*) represents a knight and a (0) represents a empty cell.

Well, the logic for this problem can be achieved by some observations and
finally build a mathematical formulation. Several pieces of paper-work might lead to the solution .

If you see the board carefully it's always optimal if we place the knights diagonally.(Two sides)

Anyway I'm not telling you the formula , try to formulate it.

However , be careful for some special cases like n = 1 or m = 1 or n = 2 or m = 2 .
Handle these cases in hand.

So, the problem is just a if-else problem and the complexity O(1)

[ When I first saw this problem ,  I used some algos like bfs/dfs and got several TLEs. Time limit is tight enough to get AC
without  O(1) solution . -_- ]
**/

#include <stdio.h>
int main()
{
    int tst, i;
    int m , n, mn, ans, x;
    scanf("%d", &tst);
    for(i=1; i<=tst; i++)
    {
        scanf("%d%d", &m, &n);
        mn = m * n;
        if(m==1 || n==1)    ans = mn;
        else if(m==2 || n==2)
        {
            if(m==2) x = n;
            else     x = m;
            if(x%4 == 1)      ans = x+1;
            else if(x%4 == 2) ans = x+2;
            else if(x%4 == 3) ans = x+1;
            else if(x%4 == 0) ans = x;
        }
        else if(mn%2 == 0) ans = mn/2;
        else ans = (mn/2)+1;
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
