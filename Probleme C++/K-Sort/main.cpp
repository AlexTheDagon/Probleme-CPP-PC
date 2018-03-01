#include <iostream>
#include <bits/stdc++.h>
#define NM 100005
#define pb push_back
#define x first
#define y second
using namespace std;
ifstream in("ksort.in");
ofstream out("ksort.out");
map<int,int> m;
int n,a[NM],s[NM],cnt,viz[NM],k;
vector<int> v[NM];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        s[i]=a[i];
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;++i)
        m[s[i]]=++cnt;
    for(int i=1;i<=n;++i)
        a[i]=m[a[i]];
    return 0;
}
