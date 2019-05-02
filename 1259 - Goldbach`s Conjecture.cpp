#include <bits/stdc++.h>
using namespace std;
vector<long long int>v;
long long int N=10000002;

bool status[10000005];
void siveve()
{
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2)
    {
        status[i]=1;
    }
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i)
            {
                status[j]=1;
            }
        }
    }
    status[1]=1;
    status[0]=1;
    for(int i=1; i<=N ; i++)
    {
        if(status[i]==0)
        {
            v.push_back(i);
        }
    }

}

int main()
{
    siveve();
    long long int a,b,c,i,p,x=0,q,n,k;
    cin>>a;
    for(k=0;k<a;k++){
        cin>>b;
        c=upper_bound(v.begin(),v.end(),b)-v.begin();
        n=b/2;
        for(i=c-1;i>=0;i--){
            p=v[i];
            if(p<n){
                break;
            }
            q=b-p;
            if(status[q]==0){
                x++;
            }
        }
        printf("Case %lld: %lld\n",k+1,x);
        x=0;
   }
    return 0;
}
