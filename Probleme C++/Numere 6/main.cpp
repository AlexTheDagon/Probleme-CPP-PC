#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define m 9973
#define pb push_back
using namespace std;
ifstream in("numere6.in");
ofstream out("numere6.out");
vector <int> d,cif;
int a,b;
int n1[9005],n2[9005];
int main()
{
    in>>a>>b;
    for(int i=1;i<=b;++i)if(b%i==0)d.pb(i);
    for(int i=1;i<=min(9,b);++i)
    {
        if(b%i==0)cif.pb(i);
        n1[i]=1;
    }
    for(int i=2;i<=a;++i)
    {
        if(i%2==0)
        {
            for(auto j:d)n2[j]=0;
            for(auto j:d)
            {
                for(auto c:cif)
                {
                    if(j*c<=b)n2[j*c]+=n1[j];
                }
            }
            for(auto j:d)n2[j]%=m;
        }
        else
        {
            for(auto j:d)n1[j]=0;
            for(auto j:d)
            {
                for(auto c:cif)
                {
                    if(j*c<=b)n1[j*c]+=n2[j];
                }
            }
            for(auto j:d)n1[j]%=m;
        }
    }
    if(a%2==0)out<<n2[b];
    else out<<n1[b];
    return 0;
}
