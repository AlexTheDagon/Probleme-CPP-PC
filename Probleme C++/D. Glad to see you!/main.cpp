#include <iostream>
#define inf 1000000000
using namespace std;
int n,k,nr1,nr2,m;
string s;
bool verif(int st,int dr)
{
    if(st<0 || dr>n)return 0;
    cout<<"1 "<<st<<" "<<dr<<'\n';
    cin>>s;
    return(s=="TAK");
}
int cb(int st,int dr)
{
    if(st>dr)return -1;
    while(st<dr)
    {
        m=(st+dr)/2;
        if(verif(m,m+1))dr=m;
        else st=m+1;
    }
    return st;
}
int main()
{
    cin>>n>>k;
    nr1=cb(1,n);
    nr2=cb(1,nr1-1);
    if(!verif(nr2,nr1))
    {
        nr2=cb(nr1+1,n);
    }
    cout<<"2 "<<nr1<<" "<<nr2<<'\n';
    return 0;
}
