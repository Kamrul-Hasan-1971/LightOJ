#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pb               push_back
#define         output             freopen("output.txt","wt", stdout)


vector<ll>v,v2,v1;
ll N,E;

void binarySearch(ll l, ll r,ll N,ll E)
{
    ll x,m;
    while (l <= r)
    {
        ll cnt=E;
        m=(l+r)/2;
        ll f=m;
        ll pre=0;
        ll chk=0;
        while(cnt--)
        {
            x=upper_bound(v.begin(),v.end(),f)-v.begin();
            x--;
            if(f<v[x]){
                break;
            }
            if(pre==v[x]){
                chk=1;
                break;
            }
            pre=v[x];
            f=v[x]+m;
        }
        if(x==N-1){
            v2.pb(m);
            r=m-1;
        }
        else{
            l=m+1;
        }

    }
}

void print(ll ans)
{
    ll last=N-E;
    ll now=0,i;
    for(i=0;i<N;i++){
        ll x=upper_bound(v.begin(),v.end(),now+ans)-v.begin();
        x--;
        x=min(x,last);
        i=x;
        cout<<v[x]-now<<endl;
        now=v[x];
        last++;
    }
}

int main()
{
    output;
    ll test,i,a,start,endd,mx,sum,ans,j;
    cin>>test;
    for(j=0;j<test;j++)
    {
        sum=0;
        cin>>N>>E;
        N++;E++;
        for(i=0; i<N; i++)
        {
            scanf("%lld", &a);
            sum=sum+a;
            v.pb(sum);
            v1.pb(a);
        }


        mx=v[N-1];
        binarySearch(0,mx,N,E);
        if(v2.size()!=0){
        ans=*min_element(v2.begin(),v2.end());
        }
        else{
            ans=*max_element(v1.begin(),v1.end());
        }
        printf("Case %lld: %lld\n",j+1,ans);
        print(ans);
        v.clear();
        v2.clear();
        v1.clear();
    }
    return 0;
}
