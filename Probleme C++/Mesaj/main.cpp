#include <iostream>
#include <fstream>
using namespace std;
ifstream in("mesaj.in");
ofstream out("mesaj.out");
int n,m,icuv,isec,l,aux;
string v[1005];
char mesaj[1605];
int dmin[1605],a[1605][1005],p,k;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)in>>mesaj[i];
    for(int i=0;i<n;++i)in>>v[i];
    for(int j=0;j<n;++j)a[0][j]=-1;
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(v[j].size()<=i)
            {
                if(mesaj[i]==v[j][v[j].size()-1])
                {
                    int p=i,k=(v[j].size()-1);
                    while(k>=0 && p>0)
                    {
                        if(mesaj[p]==v[j][k] && p>0)
                        {
                            k--;
                            p--;
                        }
                        else if(p>0)p--;
                    }
                    if(p>=0 && k<0)a[i][j]=p+1;
                    else a[i][j]=-1;
                }
                else a[i][j]=a[i-1][j];
            }
            else a[i][j]=-1;
        }
    }
    int act;
    for(int i=1;i<=m;++i)
    {
        dmin[i]=dmin[i-1]+1;
        for(int j=0;j<=n-1;++j)
            if(v[j].size()<=i){
                if(a[i][j]!=-1)
                {
                    act=dmin[a[i][j]-1]+i-a[i][j]+1-v[j].size();
                    dmin[i]=min(dmin[i],act);
                }
            }
    }
    out<<dmin[m];
    return 0;
}
