#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
vector<ll>v1;

int main()
{
    ll  a,i,j,cnt1=0,T,b;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> a ;
        cnt1=0;
        v1.clear();
        for( j = 0 ;j < a ;j++ )
        {
            cin >> b;
            v1.push_back(b);
        }
        for( j = 0 ;j < a ;j++ )
        {
            if(v1[j]!=j+1)
            {
                swap(v1[j],v1[v1[j]-1]);
                cnt1++;
                j--;
            }
        }
        printf("Case %lld: %lld\n",i,cnt1);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1166
