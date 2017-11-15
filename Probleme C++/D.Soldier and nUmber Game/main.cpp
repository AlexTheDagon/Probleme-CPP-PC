#include <iostream>
#include <bits/stdc++.h>
#define NM 5000005
using namespace std;
int n;
int a[NM],b[NM];
int c[NM],aux;
long long r[NM];
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for (int i=2;i<=5000000;++i)
		if(!c[i])
			for(int j=i;j<=5000000;j+=i)
				for (int x=j;x%i==0;x/=i)c[j]++;
    for(int i=2;i<=NM-5;i++)r[i]=r[i-1]+c[i];
    for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
    for(int i=1;i<=n;++i)cout<<r[a[i]]-r[b[i]]<<'\n';
}
///editorial +sursa
