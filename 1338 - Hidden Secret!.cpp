#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define   output    freopen("output.txt","wt", stdout)

int main()
{
    vector<char>v;
    vector<char>v1;
    ll a,b,c,i,p,q,r,s,d,e;
    string s1,s2;
    cin>>a;
    for(b=0; b<a; b++)
    {
        while(1)
        {
            getline(cin,s1);
            if(s1.size()==0){
                continue;
            }
            for(i=0; i<s1.size(); i++)
            {
                if(s1[i]!=' ')
                {
                    if(s1[i]>=97 && s1[i]<=122)
                    {
                        s1[i]=s1[i]-32;
                        v.push_back(s1[i]);
                    }
                    else
                    {
                        v.push_back(s1[i]);
                    }
                }
            }
            sort(v.begin(),v.end());
            break;
        }
        while(1)
        {
            getline(cin,s2);
            if(s2.size()==0){
                continue;
            }
            for(i=0; i<s2.size(); i++)
            {
                if(s2[i]!=' ')
                {
                    if(s2[i]>=97 && s2[i]<=122)
                    {
                        s2[i]=s2[i]-32;
                        v1.push_back(s2[i]);
                    }
                    else
                    {
                        v1.push_back(s2[i]);
                    }
                }
            }
            sort(v1.begin(),v1.end());
            break;
        }
        if(v==v1){
            printf("Case %lld: Yes\n",b+1);
        }
        else{
           printf("Case %lld: No\n",b+1);
        }
        v1.clear();
        v.clear();

    }
    return 0;
}
