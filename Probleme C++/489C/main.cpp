#include <iostream>

using namespace std;
int m,s,sol[105],cs;
int main()
{
    cin>>m>>s;
    if((s==0 && m>1)||9*m<s)cout<<"-1 -1";
    else
    {
        if(s==0)
        {
            cout<<"0 0";
            return 0;
        }
        ///minn
        cs=s;
        for(int i=m;i>0 && cs!=0;--i)
        {
            if(cs>9)
            {
                sol[i]=9;
                cs-=9;
            }
            else
            {
                sol[i]=cs;
                cs=0;
            }
            if(cs==0)
            {
                --sol[i];
            }
        }
        ++sol[1];
        for(int i=1;i<=m;++i)cout<<sol[i];
        cout<<" ";
        for(int i=1;i<=m;++i)sol[i]=0;
        ///maxx
        cs=s;
        for(int i=1;i<=m;++i)
        {
            if(cs>9)
            {
                sol[i]=9;
                cs-=9;
            }
            else
            {
                sol[i]=cs;
                cs=0;
            }
        }
        for(int i=1;i<=m;++i)cout<<sol[i];
    }
    return 0;
}
