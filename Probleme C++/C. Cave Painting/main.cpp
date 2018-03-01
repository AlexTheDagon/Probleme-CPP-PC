#include <iostream>
#include <unordered_set>
using namespace std;
long long n,k,r;
unordered_set <long long> s;
int main()
{
    cin>>n>>k;
    if(k>=n && k>1)
    {
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=k;++i)
    {
        r=n%i;
        if(s.find(r)!=s.end())
        {
            cout<<"No";
            return 0;
        }
        s.insert(r);
    }
    cout<<"Yes";
    return 0;
}
