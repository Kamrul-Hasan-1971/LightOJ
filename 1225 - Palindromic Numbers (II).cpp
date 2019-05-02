#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

vector<int>v1;

int main()
{
    ll a,b,c,d,i,j,k;
    string s;
    cin>>a;
    for(i=0; i<a; i++)
    {
        c=0;
        cin>>s;
        d=s.size();
        for(j=0,k=d-1; j<d/2; j++,k--)
        {
            if(s[j]!=s[k])
            {
                c=1;
            }
        }
        if(c==0)
        {
            printf("Case %lld: Yes\n",i+1);
        }
        else
        {
            printf("Case %lld: No\n",i+1);
        }
    }
    return 0;
}
