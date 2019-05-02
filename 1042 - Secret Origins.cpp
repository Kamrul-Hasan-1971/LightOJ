#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, char>
#define           pll              pair < ull, ull>
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
//#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
//#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///--------------------------------------------------------------

int rr;
vector<ll>v;
ll dctobinary(ll a)
{
    ll u,i,chk=0,s,cnt=0;
    while(1)
    {
        u=a%2;
        v.pb(u);
        a=a/2;
        if(a==0){
            break;
        }
    }
    v.pb(0);
    reverse(v.begin(),v.end());

    for(i=v.size()-1;i>=0;i--){
        if(v[i]==1){
            for(i=i;i>=0;i--){
                if(v[i]==0){
                    v[i]=1;
                    chk=1;
                    for(i=i;i>=0;i--){
                        if(v[i]==1){
                            cnt++;
                        }
                    }
                    break;
                }
                else{
                    v[i]=0;
                }
            }
            if(chk==1){
                break;
            }
        }
    }

    s=rr-cnt;

    for(i=v.size()-1;i>=0;i--){
        if(s>0){
            v[i]=1;
            s--;
        }
        else{
            break;
        }
    }

    ll base=1,val=0;
    ll len=v.size();
    for(i=len-1;i>=0;i--){
        if(v[i]==1){
            val=val+base;
        }
        base=base*2;
    }
    return val;
}


int main()
{
    ll a,b,c,d,i,j,k,mx=1,sum=0,x,s,t,chk=0;
    scanf("%lld", &a);
    for(i=0;i<a;i++){
        scanf("%lld", &b);
        rr=__builtin_popcount(b);
        ll p=dctobinary(b);
        printf("Case %lld: %lld\n",i+1,p);
        v.clear();
    }
    return 0;
}
