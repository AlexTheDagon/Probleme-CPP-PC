#include <iostream>
#include <map>
#include <queue>
using namespace std;
queue<int> q[2];
map< pair<int,int>,int > m;
int n,x,cnt;
int main()
{
    cin>>n>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        q[0].push(x);
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        q[1].push(x);
    }
    while(!q[0].empty() && !q[1].empty())
    {
        if(cnt>1000000)
        {
            cout<<"-1";
            return 0;
        }
        if(q[1].front()>q[0].front())
        {
            q[1].push(q[0].front());
            q[1].push(q[1].front());
            q[1].pop();
            q[0].pop();
        }
        else
        {
            q[0].push(q[1].front());
            q[0].push(q[0].front());
            q[1].pop();
            q[0].pop();
        }
        ++cnt;
    }
    cout<<cnt<<" ";
    if(q[0].empty())cout<<"2";
    else cout<<"1";
    return 0;
}
