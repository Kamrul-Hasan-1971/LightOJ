#include <bits/stdc++.h>
using namespace std;
# define ll long long int
#define  mod  1000000007
#define  prm  347
string s1 , s2 ;

const ll Hash(string str , ll len )
{
    ll i , power = 1 , val = 0;
    for( i= len-1 ; i >= 0 ; i-- )
    {
        val = val + (power*str[i])%mod;
        val = val % mod ;
        power = (power * prm)%mod;
    }
    return val ;
}

const ll solve()
{
    ll i , sz1 = s1.size() , sz2 = s2.size() , power = 1 ,cnt=0;
    ll h1 = Hash(s1,sz2);
    ll h2 = Hash(s2,sz2);
    if(h1==h2) cnt++;
    for( i = 1 ; i < sz2 ; i++ ) power = (power*prm)%mod;
    for( i = sz2 ; i < sz1 ; i++ )
    {
        h1 = ( h1 - (power*s1[i-sz2])%mod)%mod;
        h1 = (h1 + mod)%mod;
        h1 = (h1 * prm)%mod;
        h1 = (h1+s1[i])%mod;
        if(h1==h2) cnt++;
    }
    return cnt ;
}
int main()
{
	ll a , b , c, d , i , T , j;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> s1 >> s2 ;
        printf("Case %lld: %lld\n",i,solve());
    }
	return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1255
