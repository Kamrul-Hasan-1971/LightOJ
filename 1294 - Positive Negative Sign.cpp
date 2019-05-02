#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

vector<int>v1;

int main()
{
    ll a,b,c,i;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c;
        printf("Case %lld: %lld\n", i+1,b*c/2);
    }
    return 0;
}
