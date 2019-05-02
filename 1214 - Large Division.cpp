#include <bits/stdc++.h>
using namespace std;
vector<int>v,v1;
int main()
{
    long long int u,a,i,r,vag,p,l;
    string s;
    cin>>a;
    for(u=0; u<a; u++)
    {
        cin>>s>>r;
        if(r<0)
        {
            r=r*(-1);
        }
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='-')
            {
                continue;
            }
            v.push_back(s[i]-'0');
        }
        l=v.size();
        p=v[0];
        for(i=0;i<v.size();i++){
            if(p<r && l!=1){
                    i++;
                p=p*10+v[i];
                if(i==l-1){
                    p=p%r;
                    break;
                }
               // cout<<"p1= "<<p<<" i1 = "<<i<<endl;
                i--;
               // cout<<"p1= "<<p<<" i1 = "<<i<<endl;
            }
            else{
                p=p%r;
                if(i==l-1){
                    break;
                }
                i--;
               // cout<<"p2= "<<p<<" i2 = "<<i<<endl;
            }
        }
        //cout<<p<<endl;
        if(p==0){
            printf("Case %lld: divisible\n",u+1);
        }
        else{
            printf("Case %lld: not divisible\n",u+1);
        }
        v.clear();

    }
    return 0;
}
