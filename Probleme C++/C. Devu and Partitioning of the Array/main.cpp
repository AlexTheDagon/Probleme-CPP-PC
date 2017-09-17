#include <iostream>
#include <vector>
#define pb push_back
#define pp pop_back
using namespace std;
vector<int> a[2],sol[100005];
int n,k,p,x;
int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[x%2].pb(x);
    }
    if(a[1].size()<k-p)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=k-p;++i)
    {
        sol[i].pb(a[1].back());
        a[1].pop_back();
    }
    if((a[1].size())%2!=0)
    {
        cout<<"NO";
        return 0;
    }
    if(a[0].size()+a[1].size()/2<p)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=k-p+1;i<=k;++i)
    {
        if(!a[0].empty())
        {
            sol[i].pb(a[0].back());
            a[0].pop_back();
        }
        else
        {
            for(int j=1;j<=2;++j)
            {
                sol[i].pb(a[1].back());
                a[1].pop_back();
            }
        }
    }
    for(int j=0;j<2;++j)
        for(auto i:a[j])sol[1].pb(i);
    cout<<"YES"<<endl;
    for(int i=1;i<=k;++i)
    {
        cout<<sol[i].size()<<" ";
        for(auto j:sol[i])cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
