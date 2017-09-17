#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
#include <vector>
#include <map>
#define x first
#define y second
#define mp make_pair
#define pp pair<int,int>
using namespace std;
ifstream in("numar2.in");
ofstream out("numar2.out");
int n,a[105],m;
priority_queue <pp,vector<pp>,greater<pp> > q;
map<int,int> mm;
pp fr;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        q.push(mp(a[i],a[i]));
        mm[a[i]]=1;
    }
    for(int i=1;i<m;++i)
    {
        fr=q.top();
        q.pop();
        while(mm.find(fr.x+fr.y)!=mm.end())fr.x+=fr.y;
        fr.x+=fr.y;
        mm[fr.x]=1;
        q.push(fr);
    }
    out<<q.top().x;
    return 0;
}
