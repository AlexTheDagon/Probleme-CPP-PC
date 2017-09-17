#include <iostream>
#include <fstream>
using namespace std;
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("br.in");
ofstream out("br.out");
long long n,t,s,k,sp[30005];
long long hi,low,mid;
int main()
{
    in>>n>>t;
    for(int i=1;i<=n;++i)
    {

        in>>sp[i];
        sp[i+n]=sp[i];
    }
    for(int i=1;i<=2*n;++i)sp[i]+=sp[i-1];
    for(int i=1;i<=t;++i)
    {
        in>>k>>s;
        low=k-1;
        hi=k+n-1;
        while(hi-low>1)
        {
            mid=(hi+low)/2;
            if((sp[mid]-sp[k-1])<=s)low=mid;
            else hi=mid;
        }
        if(sp[hi]-sp[k-1]>s)--hi;
        out<<hi-k+1<<'\n';
    }
    return 0;
}
