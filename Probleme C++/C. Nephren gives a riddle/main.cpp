#include <iostream>
#include <bits/stdc++.h>
#define NM 100005
using namespace std;
long long n,q,f[NM],p;
string s[4],sol;
char rec(int grad,int poz)
{
    cout<<grad<<" "<<poz<<endl;
    if(grad==0)return s[0][poz];
    if(poz<s[1].size())return s[1][poz];
    if(poz>=s[1].size() && poz<(f[grad-1]+s[1].size()))return rec(grad-1,poz-s[1].size());
    if(poz>=f[grad-1]+s[1].size() && poz<s[1].size()+s[2].size()+f[grad-1])return s[2][poz-f[grad-1]-s[1].size()];
    if(poz>=s[1].size()+s[2].size()+f[grad-1] && poz<s[1].size()+s[2].size()+2*f[grad-1])return rec(grad-1,poz-s[1].size()-s[2].size()-f[grad-1]);
    return s[3][poz-(s[1].size()+s[2].size()+2*f[grad-1])];
}
char cc;
int main()
{
    s[0]="What are you doing at the end of the world? Are you busy? Will you save us?";
    s[1]="What are you doing while sending #";
    s[2]="#? Are you busy? Will you send #";
    s[3]="#?";
    f[0]=s[0].size();
    for(int i=1;i<=54;++i)f[i]=2*f[i-1]+s[1].size()+s[2].size()+s[3].size();
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>n>>p;
        --p;
        n=min(n,1LL*53);
        if(p<f[n])cc=rec(n,p);
        else cc='.';
        if(cc=='#')cc='"';
        sol+=cc;
    }
    cout<<sol;
    return 0;
}
