#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)


int main()
{
    int h,a,b,c,d,i,j,y,u,v,x;

    cin>>h;
    for(i=0;i<h;i++){
        cin>>a>>b>>c>>d;
        cin>>y;
        printf("Case %d:\n",i+1);
        for(j=0;j<y;j++){
            x=0;
            cin>>u>>v;
            if(u>=a && u<=c){
                if(v>=b && v<=d){
                    x=1;
                }
            }
            if(x==1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
            x=0;
        }
    }


    return 0;
}
