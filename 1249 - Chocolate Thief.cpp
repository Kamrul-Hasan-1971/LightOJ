#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll,string>
#define   output    freopen("output.txt","wt", stdout)

int main()
{

    vector<pii>v;
    ll a,b,i,j,c,d,e,vm;
    string s1;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b;
        for(j=0;j<b;j++){
            cin>>s1>>c>>d>>e;
            vm=c*d*e;
            v.push_back(make_pair(vm,s1));
        }
        sort(v.rbegin(),v.rend());
        if(v[0].first>v[1].first){
            printf("Case %lld: ",i+1);
            cout<<v[0].second<<" took chocolate from "<<v[b-1].second<<endl;
        }
        else{
            printf("Case %lld: no thief\n",i+1);
        }
        v.clear();
    }
    return 0;
}
