#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int main()
{
    vector<ll>v;
    ll a,b,c,d,i,j,sum=0,x=0,e;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c>>d;
        for(j=0;j<b;j++){
            cin>>e;
            v.push_back(e);
        }
        sort(v.begin(),v.end());
        for(j=0;j<b;j++){
            sum=sum+v[j];
            if(sum>d){
                break;
            }
            x++;
        }
        if(x>c){
            x=c;
        }
        printf("Case %lld: %lld\n",i+1,x);
        x=0;
        sum=0;
        v.clear();
    }
    return 0;
}
