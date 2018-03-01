#include <iostream>
#include <bits/stdc++.h>
#define NM 2000005
#define pb push_back
using namespace std;
map<string,long long> m;

string root,s,C,ver;
vector<string> v;
long long n,l,S[NM],k,lr;
long long sol;
int main()
{
    cin>>n;
    while(n)
    {
        s="";
        C="";
        ver='a';
        --n;
        cin>>l;
        cin>>s;
        C='a'+s;
        root="";
        for(int i=0;i<=l;++i)S[i]=0;
        k=0;
        for(int i=2;i<=l;++i)
        {
            while(k>0 && C[k+1]!=C[i])k=S[k];
            if(C[k+1]==C[i])++k;
            S[i]=k;
        }
        ///
        lr=l-S[l];
        for(int i=1;i<=lr;++i)root+=C[i];
        k=0;
        while(k<l)
        {
            ver+=root;
            k+=lr;
        }
        if(ver!=C)
        {
            root="";
            for(int i=1;i<=l;++i)root+=C[i];
        }
        if(m.find(root)==m.end())
        {
            m[root]=1;
            v.pb(root);
        }
        else ++m[root];
    }
    for(auto i:v)
        sol+=(1LL*m[i]*m[i]);
    cout<<sol;
    return 0;
}
