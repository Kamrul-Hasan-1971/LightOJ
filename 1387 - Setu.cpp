#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int main()
{
    ll a,b,i,j,amn,sum;
    string s1,s2;
    cin>>a;
    for(i=0;i<a;i++){
        sum=0;
        cin>>b;
        printf("Case %lld:\n",i+1);
        for(j=0;j<b;j++){
            cin>>s1;
            if(s1[0]=='d'){
                cin>>amn;
                sum=sum+amn;
            }
            if(s1[0]=='r'){
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
