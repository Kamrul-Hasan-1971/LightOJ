#include<bits/stdc++.h>
using namespace std;
#define mx1 5000005
#define mx2 5000002

unsigned long long int phi[mx1];
int mark[mx1];
void sievephi()
{
    long long int i,j,sum=1,s;
    for(i=1;i<=mx2;i++){
        phi[i]=i;
    }
    for(i=2;i<=mx2;i++){
        if(!mark[i]){
            for(j=i;j<=mx2;j=j+i){
                mark[j]=1;
                phi[j]=(phi[j]/i)*(i-1);

            }
        }
    }
    for(i=2;i<=mx2;i++){
        phi[i]=phi[i]*phi[i];
        phi[i]=phi[i]+phi[i-1];
    }
}


int main()
{
    sievephi();
    unsigned long long int a,b,c,i,sum;
   scanf("%llu", &a);
   for(i=0;i<a;i++){
      scanf("%llu %llu",&b,&c);
      sum=phi[c]-phi[b-1];
      printf("Case %llu: %llu\n",i+1,sum);
   }
    return 0;
}
