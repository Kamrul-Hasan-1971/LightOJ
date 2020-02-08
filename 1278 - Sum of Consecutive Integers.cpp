#include<bits/stdc++.h>
using namespace std;

#define           ll                 long long int
#define           pb                 push_back
#define           output             freopen("output.txt","wt", stdout)

bool mark[10000007];
vector<ll>prime,v1;

void sieve(ll x)
{
    ll i,j;
    mark[1] = 1;
    for(ll i =4; i<=x; i=i+2)
        mark[i]=1;

    for(i=3; i*i<=x; i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i; j<=x; j+=2*i)
                mark[j]=1;
        }
    }
    prime.pb(2);
    for(i=3; i<=x; i+=2)
    {
        if(mark[i]==0)
            prime.pb(i);
    }
}

ll prime_fact( ll n )
{
    v1.clear();
    for( int i = 0 ; prime[i]*prime[i] <= n && i <prime.size(); i++ )
    {
        if( n % prime[i] == 0 )
        {
            ll cnt = 0 ;
            while( n % prime[i] == 0 )
            {
                cnt++;
                n = n / prime[i] ;
            }
            if(prime[i]!=2) v1.pb(cnt+1);
        }
    }

    if( n > 1 && n!=2 ) v1.pb( 2 ) ;
    ll sum = 1 ;
    for( int i = 0 ; i < v1.size() ; i++ ) sum *= v1[i];
    return sum-1;
}

int main()
{
    sieve(10000002);
    ll  a,i,T;
    scanf("%lld",&T);
    for( i = 1 ; i <= T ; i++ )
    {
        scanf("%lld",&a);
        printf("Case %lld: %lld\n",i,prime_fact(a));
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1278
