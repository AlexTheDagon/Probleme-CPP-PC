#include <iostream>

using namespace std;
string s;
int n,g,b,k,fr[3],tip,c[3],pre;
int main()
{
    cin>>n>>k>>c[0]>>c[1];
    for(int i=1;i<=n;++i)
    {
        if(fr[tip]==k)
        {
            fr[tip]=0;
            tip=1-tip;
            fr[tip]=0;
            if(tip==0)s+='G';
            else s+='B';
        }
        else
        {
            pre=tip;
            if(c[0]>c[1])tip=0;
            else tip=1;
            if(tip!=pre)
            {
                fr[tip]=0;
                fr[pre]=0;
            }
            if(tip==0)s+='G';
            else s+='B';
        }
        ++fr[tip];
        --c[tip];
    }
    if(c[0]!=0 && c[1]!=0)cout<<"NO";
    else cout<<s<<endl;
    return 0;
}
///tip 0--green
///tip 1--black
