///Sa se afiseze toate numerele cu n cifre care au proprietatea ca sunt formate
///numai din cifre pare in ordine descrescatoare

#include <iostream>
using namespace std;
int n,sol[20];
void backtracking(int pas)
{
    if(pas>n)
    {
        for(int i=1;i<=n;++i)cout<<sol[i];
        cout<<'\n';
    }
    else
    {
        int fin=0;
        if(pas==1)fin=2;
        for(int i=sol[pas-1];i>=fin;i-=2)
        {
            sol[pas]=i;
            backtracking(pas+1);
        }
    }
}
int main()
{
    cin>>n;
    sol[0]=8;
    backtracking(1);
    return 0;
}
