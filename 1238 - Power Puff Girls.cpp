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
#define clear(a) memset(a, 0 , sizeof(a))

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

bool visited[21][21];
int cost[21][21];
int x,y;
char ara[21][21];
queue<pii>q;


int BFS(int a,int b,int c,int d)
{
    while(!q.empty())
    {
        q.pop();
    }
    clear(visited);
    q.push(pii(a,b));
    visited[a][b]=1;
    cost[a][b]=0;

    while(!q.empty())
    {
        pii p=q.front();
        q.pop();

        if(p.first==c && p.second==d)
        {
            return cost[p.first][p.second];
        }

        for(int i=0; i<4; i++)
        {
            int s=p.first+fx[i];
            int r=p.second+fy[i];

            if((s>=0 && s<x) && (r>=0 && r<y) && !visited[s][r] && ara[s][r]!='#' && ara[s][r]!='m')
            {

                visited[s][r]=1;
                cost[s][r]=cost[p.first][p.second]+1;
                q.push(pii(s,r));
            }
        }

    }
}

int main()
{
    int a,b,c,i,j,k,first,second,third,fourth,fifth,sixth,home1,home2;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>x>>y;

        for(j=0; j<x; j++)
        {
            for(k=0; k<y; k++)
            {
                cin>>ara[j][k];
                if(ara[j][k]=='a')
                {
                    first=j;
                    second=k;
                }
                else if(ara[j][k]=='b')
                {
                    third=j;
                    fourth=k;
                }
                else if(ara[j][k]=='c')
                {
                    fifth=j;
                    sixth=k;
                }
                else if(ara[j][k]=='h')
                {
                    home1=j;
                    home2=k;
                }
            }
        }
        int m=BFS(first,second,home1,home2);
        int n=BFS(third,fourth,home1,home2);
        int o=BFS(fifth,sixth,home1,home2);

        int r=max3(m,n,o);
        printf("Case %d: %d\n", i+1,r);

    }

}
