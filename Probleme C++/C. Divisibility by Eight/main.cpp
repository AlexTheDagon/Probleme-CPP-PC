#include <iostream>

using namespace std;
string s;
int nr,sem,sol,n;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n-2 && sem==0;++i)
    {
        for(int j=i+1;j<n-1 && sem==0;++j)
        {
            for(int k=j+1;k<n && sem==0;++k)
            {
                nr=(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
                if(nr%8==0)
                {
                    sol=nr;
                    sem=1;
                }
            }
        }
    }
    for(int j=0;j<n-1 && sem==0;++j)
    {
        for(int k=j+1;k<n && sem==0;++k)
        {
            nr=(s[j]-'0')*10+(s[k]-'0');
            if(nr%8==0)
            {
                sol=nr;
                sem=1;
            }
        }
    }
    for(int k=0;k<n && sem==0;++k)
    {
        nr=(s[k]-'0');
        if(nr%8==0)
        {
            sol=nr;
            sem=1;
        }
    }
    if(sem)
    {
        cout<<"YES"<<'\n'<<sol;
    }
    else cout<<"NO";
    return 0;
}
