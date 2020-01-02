#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
#define           zero(a)            memset(a,0,sizeof a)
vector<ll>v1;

int main()
{
    ll  a,i,j,b,T;
    scanf("%lld",&T);
    for( i = 1 ; i <= T ; i++ )
    {
        scanf("%lld",&a);
        ll ara[a+5] ,chk=0;
        zero(ara);
        v1.clear();
        for( j = 1 ; j <= a ; j++ )
        {
            scanf("%lld",&b);
            v1.push_back(b);
        }
        sort(v1.begin(),v1.end());
        if(v1.back()<a)
        {
            for( j = 0 ; j < a ; j++ )
            {
                if(ara[v1[j]]==0)
                {
                    ara[v1[j]]=1;
                }
                else if(ara[a-v1[j]-1]==0)
                {
                    ara[a-v1[j]-1]=1;
                }
                else
                {
                    chk=1;
                    break;
                }
            }
        }
        else chk = 1 ;
        if(chk==1) printf("Case %lld: no\n",i);
        else printf("Case %lld: yes\n",i);
    }
    return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1374
