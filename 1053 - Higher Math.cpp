#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

vector<int>v1;

int main()
{
    ll a,b,c,d,i;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c>>d;
        v1.push_back(b);
        v1.push_back(c);
        v1.push_back(d);
        sort(v1.begin(),v1.end());
        if(((v1[0]*v1[0])+(v1[1]*v1[1]))==(v1[2]*v1[2])){
            printf("Case %lld: yes\n",i+1);
        }
        else{
            printf("Case %lld: no\n",i+1);
        }
        v1.clear();
    }
    return 0;
}
