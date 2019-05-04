#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long int,long long int>
#define ll long long int
vector<pii>v;

int main()
{
    long long int a,b,c,d,e,f,g,i;
    cin>>a;
    for(i=0;i<a;i++){
        cin>>b>>c>>d>>e>>f>>g;
        ll p=d-b;
        ll x=f-p;
        ll q=c-e;
        ll y=g+q;
        ll xx=(b*e)-(c*d);
        ll yy=(d*g)-(e*f);
        ll zz=(f*y)-(g*x);
        ll nn=(x*c)-(y*b);
        ll res=(xx+yy+zz+nn)/2;
        printf("Case %lld: %lld %lld %lld\n",i+1,x,y,abs(res));
    }
    return 0;
}
