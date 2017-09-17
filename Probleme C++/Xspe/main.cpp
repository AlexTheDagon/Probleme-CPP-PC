#include <iostream>
#include <stack>
#include <fstream>
#define mp make_pair
#define x first
#define y second
using namespace std;
ifstream in("xspe.in");
ofstream out("xspe.out");
int a[1000005],n;
stack<pair<int,int> > s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=n;++i)
    {
        if(s.empty())s.push(mp(a[i],i));
        else
        {
            while(!s.empty() && s.top().x>a[i])
            {
                a[s.top().y]+=a[i];
                s.pop();
            }
            s.push(mp(a[i],i));
        }
    }
    for(int i=1;i<=n;++i)out<<a[i]<<" ";
    return 0;
}
