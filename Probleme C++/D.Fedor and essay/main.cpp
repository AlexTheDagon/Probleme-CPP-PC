#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
string a,b;
map<string, int> mapp;
int cuv,n,m,rn,cur;
pair<int, int> r[500005];
vector<int> v[500005],text;
int viz[500005],ga,gb;
priority_queue<pair<pair<int, int>,int> > q;
long long ansr,anslen;
int get(string s)
{
	string t;
	for(auto i:s)
    {
		if(i>='A' && i<='Z')t.pb(i+'a'-'A');
		else t.pb(i);
	}
	if(mapp[t])return mapp[t];
	mapp[t]=++cuv;
	rn=0;
	for(auto i:t)if(i=='r')++rn;
	r[mapp[t]]=mp(-rn,-t.size());
	q.push(mp(mp(-rn,-t.size()),mapp[t]));
	return mapp[t];
}


int main()
{
	cin>>m;
	for(int i=1;i<=m;++i)
    {
		string s;
		cin>>s;
		text.pb(get(s));
	}
	cin>>n;
	for(int i=1;i<=n;++i)
    {
		cin>>a>>b;
		ga=get(a);
        gb=get(b);
		v[gb].pb(ga);
	}
    while(!q.empty())
    {
        cur=q.top().y;
        q.pop();
        if(!viz[cur])
        {
            viz[cur]=1;
            for(auto j:v[cur])
            {
                if(r[cur]>r[j])
                {
                    r[j]=r[cur];
                    q.push(mp(r[j],j));
                }
            }
        }
    }
	for(auto i:text)
	{
		ansr-=r[i].x;
		anslen-=r[i].y;
	}
	cout<<ansr<<" "<<anslen;
}
///solutie
