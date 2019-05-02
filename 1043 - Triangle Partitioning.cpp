#include<bits/stdc++.h>

using namespace std;
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

double ratioo(double ab,double ac, double bc, double ad)
{
    double ae,de,bigtrianglearea,smalltrianglearea,trapheziumarea,s1,s2,ratt;

    ae=(ad*ac)/ab;
    de=(ad*bc)/ab;

    s1=(ab+bc+ac)/2.0;
    s2=(ad+de+ae)/2.0;

    bigtrianglearea= sqrt(s1 * (s1-ab)* (s1-bc) *(s1-ac));
    smalltrianglearea= sqrt(s2 * (s2-ad)* (s2-de) *(s2-ae));

    trapheziumarea=bigtrianglearea-smalltrianglearea;
    ratt=smalltrianglearea/trapheziumarea;
    return ratt;

}

double BS(double ab,double ac, double bc, double ratio)
{
    double ad,high=ab,low=0.0,mid;

    for(int i=0; i<100; i++)
    {
        mid=(high+low)/2.0;
        ad=mid;
        if(ratioo(ab,ac,bc,ad)>ratio)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    return ad;
}

int main()
{
    int a,i;
    double  ab,ac,bc,ratio,ans;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>ab>>ac>>bc>>ratio;
        ans= BS (ab,ac,bc,ratio);
        cout<<"Case "<<i+1<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }

}
