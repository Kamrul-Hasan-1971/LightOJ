#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int
string s1, s2="####";

int main()
{
    ll  a,i,j,cnt1=0,T;
    cin >> T ;
    for( i = 1 ; i <= T ; i++ )
    {
        cin >> a >> s1 ;
        s1+=s2;
        cnt1=0;
        for( j = 0 ;j < a ;j++ )
        {
            if(s1[j]=='.')
            {
                cnt1++;
                s1[j]='#';
                s1[j+1]='#';
                s1[j+2]='#';
            }
        }
        printf("Case %lld: %lld\n",i,cnt1);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1389
