#include <iostream>
#include <cctype>
using namespace std;
int n,m,dig=1000,alph=1000,semn=1000;
char c;
int main()
{
   cin>>n>>m;
   for(int i=1;i<=n;++i)
   {
       for(int j=1;j<=m;++j)
       {
           cin>>c;
           if(isdigit(c))dig=min(dig,min(m-j+1,j-1));
           else
           {
               if(isalpha(c))alph=min(alph,min(m-j+1,j-1));
               else semn=min(semn,min(m-j+1,j-1));
           }
       }
   }
   cout<<semn+alph+dig;
    return 0;
}
