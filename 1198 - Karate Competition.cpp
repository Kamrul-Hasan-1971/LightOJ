#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
vector<ll>v1,v2;

int main()
{
    ll  a,i,j,cnt1=0,T,b,k;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> a ;
        v1.clear();
        v2.clear();
        cnt1 = 0;
        for( j = 0 ; j < a ; j++ )
        {
            cin >> b ;
            v1.push_back(b);
        }
        for( j = 0 ; j < a ; j++ )
        {
            cin >> b;
            v2.push_back(b);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        for( k = 0 ; k < a ; k++ )
        {
            for( j = a-1 ; j >= 0 ; j-- )
            {
                if(v2[j]!=-1 && v1[k]>v2[j])
                {
                    v2[j]=-1;
                    v1[k]=-1;
                    cnt1+=2;
                    break;
                }
            }
        }
        for( k = 0 ; k < a ; k++ )
        {
            if(v1[k]==-1) continue;
            for( j = 0 ; j < a ; j++ )
            {
                if(v1[k]==v2[j])
                {
                    v2[j]=-1;
                    cnt1++;
                    break;
                }
            }
        }
        printf("Case %lld: %lld\n",i,cnt1);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1198
