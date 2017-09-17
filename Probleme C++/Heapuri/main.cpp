#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
#include <vector>
#define pp pair<int,int>
#define mp make_pair
#define NM 200005
#define x first
#define y second
using namespace std;
ifstream in("heapuri.in");
ofstream out("heapuri.out");
priority_queue<pp,vector<pp>,greater<pp> > q;
int el[NM],a,b,n,ord;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a;
        if(a==1)
        {
            in>>b;
            q.push(mp(b,++ord));
        }
        if(a==2)
        {
            in>>b;
            el[b]=1;
        }
        if(a==3)
        {
            while(el[q.top().y]==1)q.pop();
            out<<q.top().x<<'\n';
        }
    }
    return 0;
}
