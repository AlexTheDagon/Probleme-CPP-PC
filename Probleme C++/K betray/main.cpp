#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("kbetray.in");
ofstream out("kbetray.out");
long long n,k,a[100005],b[100005],col2,col1,fol,sem,s;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i]>>b[i];
        if(a[i]<b[i])swap(a[i],b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1,cmp);
    col1=1;
    for(int i=1;i<=n;++i)
    {
        if(k>0 && a[i]<b[col1])
        {
            s+=b[col1];
            col1++;
            k--;
        }
        else s+=a[i];
    }
    out<<s;
    return 0;
}
