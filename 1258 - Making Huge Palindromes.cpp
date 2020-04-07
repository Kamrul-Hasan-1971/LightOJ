#include <bits/stdc++.h>
using namespace std;
# define ll int
string s1 , s2 , concat ;
ll Z[2000006];
void getZarr(ll Z[])
{
    ll i , R = 0, L = 0 , sz = concat.size();
    for( i = 1 ; i <= sz ; i++ )
    {
        if(i>R)
        {
            L=R=i;
            while( R < sz && concat[R-L]==concat[R]) R++;
            Z[i] = R-L ;
            R--;
        }
        else
        {
            int k = i-L ;
            if(Z[k]<R-i+1)
            {
                Z[i]=Z[k];
            }
            else
            {
                L=i;
                while(R<sz && concat[R-L]==concat[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

const ll solve()
{
    concat = s2+"$"+s1;
    ll i , sz = concat.size() , sz2 = s2.size(),mx=0;
    getZarr(Z);
    for( i = sz2+1 ; i< sz ; i++) if(mx<Z[i]&&i+Z[i]==sz)mx =Z[i];
    return mx ;
}
int main()
{
	ll a , b , c, d , i , T , j;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> s1 ;
        ll x = s1.size();
        s2 = s1;
        reverse(s2.begin(),s2.end());
        printf("Case %d: %d\n",i,x-solve()+x);
    }
	return 0;
}
//http://lightoj.com/volume_showproblem.php?problem=1258
