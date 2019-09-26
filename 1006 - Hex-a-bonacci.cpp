#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           mod              10000007
#define           zero(a)          memset(a,-1,sizeof a)

ll  a, b, c, d, e, f  ;

ll dp[10005];

ll fun(ll n)
{
    if( n == 0 )
        return a%mod;
    if( n == 1 )
        return b%mod;
    if( n == 2 )
        return c%mod;
    if( n == 3 )
        return d%mod;
    if( n == 4 )
        return e%mod;
    if( n == 5 )
        return f%mod;
    if(dp[n]!=-1)
        return dp[n] ;
    dp[n] = ( fun(n-1) % mod + fun(n-2) % mod + fun(n-3) % mod + fun(n-4) % mod + fun(n-5) % mod + fun(n-6) %mod ) % mod ;
    return dp[n] % mod ;
}

int main()
{
    ll test, n,i ;
    scanf("%lld",&test);
    for( i  = 1 ; i <= test ; i++ )
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        zero(dp);
        printf("Case %lld: %lld\n",i,fun(n));
    }
    return 0;
}

