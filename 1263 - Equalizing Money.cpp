#include<bits/stdc++.h>
#include<string>

///...................................*****.................................................///
///                  Kamrul Hasan (icthasn36@gmail.com)                                     ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
vector<ll>v[1005];
ll taka[1005];
ll visited[1005];
ll cost,cnt=1;
void BFS(ll a)
{
    queue<ll>q;
    visited[a]=1;
    cost=cost+taka[a];
    q.push(a);

    while(!q.empty())
    {
        ll w=q.front();
        q.pop();
        for(ll i=0; i<v[w].size(); i++)
        {
            ll rr=v[w][i];
            if(visited[rr]==0)
            {
                cnt++;
                visited[rr]=1;
                cost=cost+taka[rr];
                q.push(rr);
            }
        }
    }
    return;
}
int main()
{
    //output;
    ll a,b,c,d,i,z=0,y=0,r,j,sum=0,p,cal,dis,zz=0;
    scanf("%lld",&a);
    for(i=0; i<a; i++)
    {
        scanf("%lld %lld",&c, &d);
        for(j=1; j<=c; j++)
        {
            scanf("%lld",&taka[j]);
            sum=sum+taka[j];
        }
        for(j=0; j<d; j++)
        {
            scanf("%lld %lld",&r, &p);
            v[r].pb(p);
            v[p].pb(r);
        }
        if(sum%c!=0)
        {
            printf("Case %lld: No\n",i+1);
            zz=0;
            cnt=1;
            cost=0;
            sum=0;
            for(j=1; j<=c; j++)
            {
                v[j].clear();
                taka[j]=0;
            }
            continue;
        }
        dis=sum/c;
        for(j=1; j<=c; j++)
        {
            if(visited[j]==0)
            {
                BFS(j);
                if(cost%cnt==0 && cost/cnt==dis)
                {
                }
                else
                {
                    zz=1;
                    break;
                }
                cnt=1;
                cost=0;
            }
        }

        if(zz==0)
        {
            printf("Case %lld: Yes\n",i+1);
        }
        else
        {
            printf("Case %lld: No\n",i+1);
        }
        zz=0;
        cnt=1;
        cost=0;
        sum=0;
        for(j=1; j<=c; j++)
        {
            v[j].clear();
            visited[j]=0;
            taka[j]=0;
        }
    }
    return 0;
}
