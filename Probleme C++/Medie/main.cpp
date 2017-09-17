#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
ifstream in("medie.in");
ofstream out("medie.out");
int x,fr[15005],n;
vector <int> v;
long long nr,rez;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        if(fr[x]==0)v.pb(x);
        ++fr[x];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            nr+=fr[v[i]]*fr[v[j]]*fr[2*v[i]-v[j]];
        }
        nr+=(fr[v[i]]*(fr[v[i]]-1)*(fr[v[i]]-2)/2);
    }
    out<<nr;
    return 0;
}
