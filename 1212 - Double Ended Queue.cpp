#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///



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
#define zero(a) memset(a, 0 , sizeof(a))

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int main()
{
    output;
    vector<ll>lef;
    ll b,c,d,a,i,e,f,g,j,o;
    string s;
    cin>>a;
    for(i=0; i<a; i++)
    {
        lef.clear();
        printf("Case %lld:\n",i+1);
        cin>>b>>c;
        for(j=1;j<=c;j++){
            cin>>s;
            if(s[2]=='s'){
                cin>>e;
                if(lef.size()==b){
                    printf("The queue is full\n");
                }
                else if(s[4]=='L'){
                    lef.insert(lef.begin()+0,e);
                    printf("Pushed in left: %lld\n",e);
                }
                else{
                    lef.pb(e);
                    printf("Pushed in right: %lld\n",e);
                }
            }
            else{
                if(lef.size()==0){
                    printf("The queue is empty\n");
                }
                else if(s[3]=='L'){
                    o=lef[0];
                    lef.erase(lef.begin()+0);
                    printf("Popped from left: %lld\n",o);
                }
                else{
                    o=lef[lef.size()-1];
                    lef.pop_back();
                    printf("Popped from right: %lld\n",o);
                }
            }
        }
    }
    return 0;
}
