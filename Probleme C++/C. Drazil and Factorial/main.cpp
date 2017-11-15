#include <iostream>
#include <algorithm>
using namespace std;
string nr[]={"","","2","3","322","5","53","7","7222","7332"};
string s,sol;
int n;
int main()
{
    cin>>n>>s;
    sort(s.begin(),s.end());
    for(int i=n-1;i>=0;--i)sol+=nr[s[i]-'0'];
    sort(sol.begin(),sol.end());
    for(int i=sol.size()-1;i>=0;--i)cout<<sol[i];
    return 0;
}
