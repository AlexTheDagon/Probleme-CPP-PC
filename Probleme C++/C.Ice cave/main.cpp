#include <iostream>
#define KM 505
#define NM 100005
#define MM 1000000007
using namespace std;


int n,m,xst,yst,xfn,yfn,viz[KM][KM];
char a[KM][KM];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void lee(int i,int j)
{
	viz[i][j]=1;
	for (int d=0;d<4;++d)
	{
		int ii=i+dx[d];
		int jj=j+dy[d];
		if(viz[ii][jj]==0 && a[ii][jj]=='.')lee(ii,jj);
	}
}
int cnt(int i,int j)
{
	int c=0,ii,jj;
	for (int d=0;d<4;++d)
	{
		ii=i+dx[d];
		jj=j+dy[d];
		if(a[ii][jj]=='.')++c;
	}
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)cin>>a[i][j];
	cin>>xst>>yst;
	cin>>xfn>>yfn;
	a[xst][yst]='.';
	if(xst==xfn && yst==yfn)
	{
		if(cnt(xst,yst))cout<<"YES";
		else cout<<"NO";
	}
	else
    {
        if(a[xfn][yfn]=='X')
        {
            a[xfn][yfn]='.';
            lee(xst,yst);
            if(viz[xfn][yfn])cout<<"YES";
            else cout<<"NO";
        }
        else
        {
            lee(xst,yst);
            if(viz[xfn][yfn] && cnt(xfn,yfn)>1)cout<<"YES";
            else cout<<"NO";
        }
    }
    return 0;
}
