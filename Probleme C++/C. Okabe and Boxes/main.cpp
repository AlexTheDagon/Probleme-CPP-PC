#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
string s;
int a,act,sol,n;
set<int> ord;
vector<int> v;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;++i)
    {
        cin>>s;
        if(s=="add")
        {
            cin>>a;
            v.pb(a);
        }
        else
        {
            ++act;
            if(!v.empty())
            {
                if(v[v.size()-1]!=act)
                {
                    ++sol;
                    for(auto i:v)ord.insert(i);
                    v.clear();
                    ord.erase(act);
                }
                else v.pop_back();
            }
            else ord.erase(act);
        }
    }
    cout<<sol;
    return 0;
}
