#include <bits/stdc++.h>
using namespace std;
double logg[1000010];

void loggg()
{
    int i;
    for(i=1;i<=1000005;i++){
        logg[i]=logg[i-1]+log(i);
    }
}


int main()
{
    loggg();
    long long a,num,base,d,i;
    scanf("%lld", &a);
    for(i=0;i<a;i++){
        scanf("%lld %lld", &num, &base);
        d=logg[num]/log(base)+1;
        printf("Case %lld: %lld\n",i+1,d);
    }
    return 0;
}
