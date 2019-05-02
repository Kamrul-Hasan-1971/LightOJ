#include <bits/stdc++.h>
#define output freopen("output.txt","wt",stdout)
using namespace std;
set<long long int>s;
int main()
{
   // output;
    long long int a,b,c,d,i,m,j,k,cnt=0;
    cin>>a;
    for(k=0; k<a; k++)
    {
        cin>>b>>c;
        d=b-c;
        m=sqrt(d+1);
        for(i=1; i<=m; i++)
        {
            if(d%i==0)
            {
                if(i>c)
                {
                    s.insert(i);
                }
                if((d/i)>c)
                {
                    s.insert(d/i);
                }
            }
        }
        printf("Case %lld: ",k+1);
        if(s.size()==0)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        for(auto j : s)
        {
            cnt++;
            if(cnt==s.size())
            {
                cout<<j;
            }
            else
            {
                cout<<j<<" ";
            }
        }
        s.clear();
        cnt=0;
        cout<<endl;
    }
    return 0;
}
