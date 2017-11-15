#include <iostream>

using namespace std;
int fr[300008];
char c;
int x,n;
int b2(long long nr)
{
	int aux,pot=1,ans=0;
	while(nr>0)
    {
		aux=nr%10;
		if(aux%2==1)ans+=pot;
		pot*=2;
		nr/=10;
	}
	return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>c>>x;
        if(c=='+')++fr[b2(x)];
        if(c=='-')--fr[b2(x)];
        if(c=='?')cout<<fr[b2(x)]<<'\n';
    }
    return 0;
}
