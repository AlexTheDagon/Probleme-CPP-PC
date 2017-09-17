#include <iostream>

using namespace std;
string s;
int poz,l;
int main()
{
    cin>>s;
    l=s.size();
    while(poz<l && s[poz]!='h')++poz;
    ++poz;
    while(poz<l && s[poz]!='e')++poz;
    ++poz;
    while(poz<l && s[poz]!='l')++poz;
    ++poz;
    while(poz<l && s[poz]!='l')++poz;
    ++poz;
    while(poz<l && s[poz]!='o')++poz;
    if(poz>=s.size())cout<<"NO";
    else cout<<"YES";
    return 0;
}
