#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;

ifstream f("tsunami.in");
ofstream g("tsunami.out");

queue < pair <int,int> > q;
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
int viz[1005][1005],inund=0,ii,jj,N,M,H,ter[1005][1005],i,j;
 pair <int,int> a,b;
void fille(int i,int j)
{
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for(int k=0;k<4;k=k+1)
        {
            ii=i+di[k];
            jj=j+dj[k];
            if(ter[ii][jj]!=0 && ter[ii][jj]<H && !viz[ii][jj])
            {
                inund++;
                q.push(make_pair(ii,jj));
                viz[ii][jj]=1;
            }
        }
    }
}

int main()
{
    cin>>a.x>>a.y>>b.x>>b.y;
    cout<<(a>b);
    return 0;
}
