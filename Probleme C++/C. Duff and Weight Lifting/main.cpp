#include <iostream>
#define NM 1000005
using namespace std;
int put[2*NM],n,w,sol;
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>w;
        ++put[w];
    }
    for(int i=0;i<=2*NM-5;++i)
    {
        if(put[i])
        {
            if(put[i]%2)++sol;
            put[i]/=2;
            put[i+1]+=put[i];
        }
    }
    cout<<sol;
    return 0;
}
