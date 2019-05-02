#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)


int main()
{
    int a,b,c,i,sm,dwn=0;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c;
        dwn=c;
        if(b>c){
            dwn=b+(b-c);
        }
        sm=(dwn*4)+19;
        printf("Case %d: %d\n", i+1, sm);
    }
    return 0;
}
