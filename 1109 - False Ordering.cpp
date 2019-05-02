#include<bits/stdc++.h>
using namespace std;
int ara[1005];
vector<int>v1[300];
int mx;

void findPrime()
{
    int i,j;
    for(i=4; i<=1000; i=i+2)
    {
        ara[i]=1;
    }
    ara[1]=1;

    for(i=3; i<=1000; i=i+2)
    {
        if(ara[i]==0)
        {
            for(j=i*i; j<=1000; j=j+(i*2))
            {
                ara[j]=1;
            }
        }
    }
}

void divisor(int n)
{
    int p=0,i;
    int x=sqrt(n+1);
    for(i=2; i<=x; i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                p++;
            }
            else
            {
                p=p+2;
            }
        }
    }
    if(mx<p)
    {
        mx=p;
    }
    v1[p].push_back(n);
}


int main()
{
    vector<int>v;
    int i,j,t,h;
    findPrime();
    v.push_back(1);
    for(i=1000; i>=1; i--)
    {
        if(ara[i]==0)
        {
            v.push_back(i);
        }
        else
        {
            divisor(i);
        }
    }
    for(i=1; i<=mx; i++)
    {
        sort(v1[i].rbegin(),v1[i].rend());
        for(j=0; j<v1[i].size(); j++)
        {
            v.push_back(v1[i][j]);
        }
    }
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>h;
        printf("Case %d: %d\n",q+1,v[h-1]);
    }
    return 0;
}
