#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

vector<int>v1;

int main()
{
    ll a,b,c,d,i,j,k;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b;
        c=__builtin_popcount(b);
        if(c%2==0){
            printf("Case %lld: even\n",i+1);
        }
        else{
            printf("Case %lld: odd\n",i+1);
        }
    }
    return 0;
}
