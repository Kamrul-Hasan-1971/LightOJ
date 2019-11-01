#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           all(v)           v.begin(),v.end()
#define           pii                pair < ll, ll>
#define           fs                 first
#define           pb                 push_back

vector<ll>res;
set<pii>st;
vector<pii>v;

int main()
{
    ll T , n , d , i , j , inp ,cnt1  ;
    pii first ;
    scanf("%lld",&T);
    for( i = 1 ;i <= T ; i++ )
    {
        st.clear();
        res.clear();
        v.clear();
        cnt1=0;
        ll x = 0 ;
        scanf("%lld%lld",&n,&d);
        for( j = 0 ; j < n ; j++ )
        {
            scanf("%lld",&inp);
            v.pb(pii(inp,j));
            st.insert(pii(inp,j));
            cnt1++;
            if( cnt1 == d )
            {
                res.pb((*st.rbegin()).fs-(*st.begin()).fs);
                st.erase(v[x]);
                cnt1--;
                x++;
            }
        }
        ll y = *max_element(all(res));
        printf("Case %lld: %lld\n",i,y);
    }

    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1093
