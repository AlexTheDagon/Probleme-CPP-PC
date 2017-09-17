#include <iostream>
#include <string.h>
using namespace std;
char s[100005];
int a[200],x=1<<29,l;
int main()
{
    cin.getline(s,100003);
    l=strlen(s);
    for(int i=0;i<l;++i)
    {
        ++a[s[i]-'A'];
    }
    x=min(x,a['B'-'A']);
    x=min(x,a['u'-'A']/2);
    x=min(x,a['l'-'A']);
    x=min(x,a['a'-'A']/2);
    x=min(x,a['s'-'A']);
    x=min(x,a['b'-'A']);
    x=min(x,a['r'-'A']);
    cout<<x;
    return 0;
}
