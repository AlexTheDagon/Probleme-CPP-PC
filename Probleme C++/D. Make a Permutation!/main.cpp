#include <iostream>
#include <vector>
#define pb push_back
#define NM 200005
using namespace std;
int nefolmin,ramas,fol[NM],perm[NM],n,ind=1,sem[NM];
vector<int> nefol;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>perm[i];
        if(fol[perm[i]])++ramas;
        ++fol[perm[i]];
    }
    for(int i=1;i<=n;++i)if(!fol[i])nefol.pb(i);
    for(auto i:nefol)
    {
        while(fol[perm[ind]]==1 || (perm[ind]<i && sem[perm[ind]]==0))
        {
            if(perm[ind]<i)sem[perm[ind]]=1;
            ++ind;
        }
        --fol[perm[ind]];
        perm[ind]=i;
    }
    cout<<ramas<<endl;
    for(int i=1;i<=n;++i)cout<<perm[i]<<" ";
    return 0;
}
