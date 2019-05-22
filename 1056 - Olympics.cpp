#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
int main()
{
    ll a,i;
    double b,c;
    scanf("%lld",&a);
    for(i=0;i<a;i++){
        scanf("%lf : %lf",&b ,&c);
        double r=(sqrt(b*b + c*c))/2.0;
        double theta = acos((r*r + r*r - c*c)/(2.0 * r*r));
        double s= r*theta;
        double x=400.0/(2.0*b + 2.0*s);
        printf("Case %lld: %.10lf %.10lf\n",i+1,b*x,c*x);

    }
    return 0;
}
