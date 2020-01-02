#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
vector<ll>v1;

int main()
{
    ll  a,i,j,b,T;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> a ;
        v1.clear();
        v1.push_back(0);
        for( j = 0 ; j < a ; j++ )
        {
            cin >> b ;
            v1.push_back(b);
        }
        ll low = 0 , high = v1.back() , ans = 0 ;
        while( low <= high )
        {
            ll mid = (low+high)/2;
            ll temp = mid ;
            for( j = 1 ; j <= a ; j++ )
            {
                ll gap = v1[j]-v1[j-1];
                if( gap > mid )
                {
                    mid=-1;
                    break;
                }
                else if( mid == gap )
                {
                    mid--;
                }
            }
            if(mid<0)
            {
                low = temp + 1 ;
            }
            else{
                high = temp - 1 ;
                ans = temp ;
            }
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1425
