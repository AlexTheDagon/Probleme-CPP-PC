#include <iostream>
#include <math.h>
#define NM 1005
using namespace std;
int e,n,aux,lg,sem,st,sum,inplus;
int main()
{
    cin>>e>>n;
    while(e!=0 && n!=0)
    {
        aux=n;
        lg=0;
        inplus=0;
        while(aux>1)
        {
            aux/=2;
            ++lg;
        }
        if(lg<e)cout<<lg+1<<'\n';///bine
        else
        {
            if(e==1)cout<<n<<'\n';///bine
            else
            {
                while(e>2)
                {
                    n=n/2;
                    --e;
                    ++inplus;
                }
                sem=0;
                st=0;
                while(sem==0)
                {
                    ++st;
                    if(st*(st+1)/2>=n)sem=1;
                }
                cout<<st+inplus<<'\n';
            }
        }
        cin>>e>>n;
    }
    return 0;
}
