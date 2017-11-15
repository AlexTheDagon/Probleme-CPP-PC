#include <iostream>
#include <string>
using namespace std;
string a,b;
string minn(string s)
{
    if(s.size()%2==1)return s;
    string s1=minn(s.substr(0,s.size()/2));
    string s2=minn(s.substr(s.size()/2, s.size()));
    if(s1<s2)return s1+s2;
    else return s2+s1;
}
int main()
{
    cin>>a>>b;
    if(minn(a)==minn(b))cout<<"YES";
    else cout<<"NO";
    return 0;
}
