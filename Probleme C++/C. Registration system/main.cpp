#include <iostream>
#include <map>
#define mp make_pair
using namespace std;
map<string,int> m;
string s;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        if(m.find(s)==m.end())
        {
            cout<<"OK";
            m[s]=1;
        }
        else
        {
            cout<<s<<m[s];
            ++m[s];
        }
        cout<<endl;
    }
    return 0;
}
