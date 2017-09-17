#include <iostream>

using namespace std;
int r,b,y,g,semne,ca[200],sr,sb,sy,sg,lg;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='!')++semne;
    }
    lg=s.size();
    while(semne>0)
    {
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='!')
            {
                sr=1;
                sb=1;
                sy=1;
                sg=1;
                for(int j=max(0,i-3);j<min(lg,i+4);++j)
                {
                    if(j!=i)
                    {
                        if(s[j]=='R')sr=0;
                        if(s[j]=='B')sb=0;
                        if(s[j]=='G')sg=0;
                        if(s[j]=='Y')sy=0;
                    }
                }
                if(sr+sb+sg+sy==1)
                {
                    --semne;
                    if(sr==1)
                    {
                        ++r;
                        s[i]='R';
                    }
                    if(sb==1)
                    {
                        ++b;
                        s[i]='B';
                    }
                    if(sg==1)
                    {
                        ++g;
                        s[i]='G';
                    }
                    if(sy==1)
                    {
                        ++y;
                        s[i]='Y';
                    }
                }
            }
        }
    }
    cout<<r<<" "<<b<<" "<<y<<" "<<g;
    return 0;
}
