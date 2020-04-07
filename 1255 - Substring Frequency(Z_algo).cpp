#include <bits/stdc++.h>
using namespace std;
# define ll long long int
string s1 , s2 , concat ;

void getZarr(int Z[])
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
    ll i , sz = concat.size() , sz2 = s2.size(),cnt=0;
    int Z[sz];
    memset(Z,0,sizeof Z);
    getZarr(Z);
    for( i = s2.size()+1 ; i< sz ; i++) if(Z[i]==sz2) cnt++;
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
