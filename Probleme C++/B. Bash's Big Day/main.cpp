#include <iostream>

using namespace std;
int n,ciur[100010],k,nrprime[100000],fr[100010],x,d,sem,maxx;
int main()
{

    for(int i=2;i<=100003;++i)ciur[i]=1;
    for(int i=2;i<=100003;++i)
    {
        if(ciur[i]==1)
        {
            nrprime[++k]=i;
            for(int j=i+i;j<=100003;j=j+i)ciur[j]=0;
        }
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(ciur[x]==1)
        {
            ++fr[x];
            x=1;
        }
        d=1;
        while(x>1)
        {
            if(x%nrprime[d]==0)
            {
                x=x/nrprime[d];
                sem=1;
            }
            else
            {
                if(sem==1)
                {
                    ++fr[nrprime[d]];
                    sem=0;
                }
                ++d;
            }
        }
        if(sem==1)
        {
            ++fr[nrprime[d]];
            sem=0;
        }
    }
    for(int i=0;i<=100003;++i)maxx=max(maxx,fr[i]);
    if(maxx==0)maxx=1;
    cout<<maxx;
    return 0;
}
