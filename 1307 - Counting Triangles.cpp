#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back


vector<ll>v;

int main()
{
    ll test,j,i,N,cnt,k,c,a,n,x;
    cin>>test;
    for(j=0; j<test; j++)
    {
        cnt=0;
        cin>>N;
        for(i=0; i<N; i++)
        {
            scanf("%lld", &a);
            v.pb(a);
        }
        sort(v.begin(),v.end());

        for(i=0; i<N-2; i++)
        {
            for(n=i+1; n<N; n++)
            {
                c=v[i]+v[n];

                x=lower_bound(v.begin()+n+1,v.end(),c)-v.begin();
                x--;
                cnt=cnt+(x-n);
            }
        }
        printf("Case %lld: %lld\n",j+1,cnt);
        v.clear();
    }
    return 0;
}
