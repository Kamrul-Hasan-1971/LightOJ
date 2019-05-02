#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int main()
{

    ll a,b,c,d,i,j;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b;
        if(b%2!=0 || b==2){
            printf("Case %lld: Impossible\n",i+1);
        }
        else{
            for(j=2;;j=j+2){
                if(b%j==0){
                    if((b/j)%2!=0){
                        break;
                    }
                }
            }
            printf("Case %lld: %lld %lld\n",i+1,b/j,j);
        }
    }
    return 0;
}
