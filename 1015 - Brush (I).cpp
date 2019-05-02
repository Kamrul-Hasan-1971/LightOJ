#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

vector<int>v1;

int main()
{
    ll a,b,c,d,i,j,k,sum=0;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b;
        for(j=0;j<b;j++){
            cin>>c;
            if(c<0){
                continue;
            }
            sum=sum+c;
        }
        printf("Case %lld: %lld\n",i+1,sum);
        sum=0;
    }
    return 0;
}
