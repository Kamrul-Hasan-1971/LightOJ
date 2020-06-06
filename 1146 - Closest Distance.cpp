#include<bits/stdc++.h>
using namespace std;
#define           pii       pair<double,double>
#define           eps       0.000000001
#define           ff        first
#define           ss        second
pii ara[5];
double dist( pii a , pii b)
{
    return  sqrt((a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss));
}
int main()
{
    int i, n, j,inp,t;
    scanf("%d",&t);
    for( j = 1 ; j<= t ; j++)
    {
        for( i = 1 ; i <= 4 ; i++ ) scanf("%lf%lf",&ara[i].ff,&ara[i].ss) ;
        double ac = dist(ara[1],ara[3]);
        double bd = dist(ara[2],ara[4]);

        while(abs(ac-bd)>eps)
        {
            pii a , b, c ,d ;
            a.ff=(2*ara[1].ff+ara[2].ff)/3.0;
            a.ss=(2*ara[1].ss+ara[2].ss)/3.0;
            b.ff=(ara[1].ff+2*ara[2].ff)/3.0;
            b.ss=(ara[1].ss+2*ara[2].ss)/3.0;

            c.ff=(2*ara[3].ff+ara[4].ff)/3.0;
            c.ss=(2*ara[3].ss+ara[4].ss)/3.0;
            d.ff=(ara[3].ff+2*ara[4].ff)/3.0;
            d.ss=(ara[3].ss+2*ara[4].ss)/3.0;

            ac = dist(a,c);
            bd = dist(b,d);

            if(ac>bd) ara[1]=a,ara[3]=c;
            else ara[2]=b,ara[4]=d;
        }
        printf("Case %d: %0.8f\n",j,(ac+bd)/2.0);
    }
    return 0 ;
}
//http://lightoj.com/volume_showproblem.php?problem=1146
