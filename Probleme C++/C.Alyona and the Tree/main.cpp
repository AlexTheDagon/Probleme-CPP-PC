#include <iostream>
#include <vector>
#define mp make_pair
#define x first
#define y second
using namespace std;
vector <pair<long,long> >v[100001];
int ver[100001];
int sol,a,b,n;
void dfs(int nod,long long d)
{
	if(d>ver[nod])return ;
	sol++;
	for(int i=0;i<v[nod].size();i++)dfs(v[nod][i].x,max(d+v[nod][i].y,0LL));
}
int main()
{
	cin>>n;
    sol=0;
    for(int i=0;i<n;i++)cin>>ver[i];
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        a--;
        v[a].push_back(make_pair(i,b));
    }
    dfs(0,0);
    cout<<n-sol;
    return 0;
}
///editorial +sursa
