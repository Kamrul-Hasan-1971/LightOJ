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
#define           mp               make_pair
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


vector<string>v;
int main()
{
    //output;
    ll a,b,c,d=0,e,f,g,i,p=0;
    string s,s1="http://www.lightoj.com/",s2;
    cin>>a;
    for(i=0; i<a; i++)
    {
        printf("Case %lld:\n",i+1);
        v.push_back(s1);
        while(cin>>s)
        {
            if(s=="QUIT")
            {
                v.clear();
                d=0;
                p=0;
                break;
            }
            else if(s[0]=='V')
            {
                cin>>s2;
                f=v.size();
                g=d+1;
                if(f>g)
                {
                    int r=f-g;
                    p=0;
                    for(int y=g;;)
                    {
                        p++;
                        v.erase(v.begin()+y);
                        if(p==r){
                            break;
                        }
                    }
                }
                v.push_back(s2);
                cout<<s2<<endl;
                d++;
                continue;
            }
            else if(s[0]=='B')
            {
                d--;
            }
            else if(s[0]=='F')
            {
                d++;
            }

            if(d>=v.size())
            {
                cout<<"Ignored\n";
                d--;
                if(d<0){
                    d=0;
                }
            }
            else if(d<0)
            {
                cout<<"Ignored\n";
                d++;
            }
            else
            {
                cout<<v[d]<<endl;
            }
        }
    }


    return 0;
}
