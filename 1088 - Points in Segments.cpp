#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           pii                pair < ll, ll>
#define           fs                 first
#define           scnd               second
#define           all(v)             v.begin(),v.end()

vector<ll>v2 ;
int main()
{
    int T, i, n, q, Ak , Bk , j ,inp ;
    scanf("%d", &T ) ;
    for( i = 1 ; i <= T ; i++ )
    {
        v2.clear();
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&q);
        for( j = 1 ; j <= n ; j++ )
        {
            scanf("%d",&inp);
            v2.emplace_back(inp);
        }
        sort(all(v2));

        for( j = 1 ; j <= q ; j++ )
        {
            scanf("%d%d",&Ak,&Bk);
            int p = lower_bound(all(v2),Ak)-v2.begin();
            int q = upper_bound(all(v2),Bk)-v2.begin();
            printf("%d\n",q-p);
        }
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1088
