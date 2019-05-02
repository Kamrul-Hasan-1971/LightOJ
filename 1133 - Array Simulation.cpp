#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int main()
{
    vector<ll>v;
    ll a ,b,c,d,i,j,p,q,temp,m,k;
    char ch;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c;
        for(j=0;j<b;j++){
            cin>>d;
            v.push_back(d);
        }
        for(k=0;k<c;k++){
            cin>>ch;
            if(ch=='S' || ch=='M' || ch=='D'){
                cin>>p;
            }
            else if(ch=='P'){
                cin>>p>>q;
            }

            if(ch=='S'){
                for(m=0;m<b;m++){
                    v[m]=v[m]+p;
                }
            }
            else if(ch=='M'){
                for(m=0;m<b;m++){
                    v[m]=v[m]*p;
                }
            }
            else if(ch=='D'){
                for(m=0;m<b;m++){
                    v[m]=v[m]/p;
                }
            }
            else if(ch=='R'){
                reverse(v.begin(),v.end());
            }
            else if(ch=='P'){
                temp=v[p];
                v[p]=v[q];
                v[q]=temp;
            }
        }

        printf("Case %lld:\n",i+1);
        cout<<v[0];
        for(m=1;m<b;m++){
            cout<<" "<<v[m];
        }
        cout<<endl;
        v.clear();
    }
    return 0;
}
