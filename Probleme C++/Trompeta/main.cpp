#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("trompeta.in");
ofstream out("trompeta.out");
char a[1000005],b[1000005];
stack <char> s;
int main()
{
    int i,j,m,n,dr;
    in>>n>>m;
    in>>a;
    s.push(0);
    for(i=0;i<=n-1;i++)
    {
        while(!s.empty() && (s.size()+n-i-1)>=m && s.top()<(a[i]))
        s.pop();
       s.push(a[i]);
    }
    i=n;
    while(!s.empty())
    {
        i--;
        b[i]=s.top();
        s.pop();
    }
    out<<b;
    return 0;
}
