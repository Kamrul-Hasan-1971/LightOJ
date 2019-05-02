#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)


int main()
{
    int a,i,sm,b,c,d,baki,e,f;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c;
        if(b==1 || c==1) {
            sm=max(b,c);
        }
        else if(b==2 || c==2){
            baki=0;
            d=b*c;
            e=d/8;
            f=e*8;
            baki=d-f;
            if(baki>=4){
                baki=4;
            }
            sm=e*4+baki;
        }
        else{
            int d=c/2;
            sm=d*b;
            if(c%2!=0){
                if(b%2==0){
                    sm=sm+b/2;
                }
                else{
                    sm=sm+b/2+1;
                }
            }
        }
        printf("Case %d: %d\n",i+1, sm);
    }


    return 0;
}
