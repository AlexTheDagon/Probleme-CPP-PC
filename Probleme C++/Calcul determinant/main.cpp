#include <iostream>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
void det(pii A,pii B)
{
    cout<<A.y-B.y<<"x+"<<B.x-A.x<<"y+"<<A.x*B.y-B.x*A.y<<"=0"<<'\n';
}
pii AA,BB;
int main()
{
    for(int i=1;i<=20;++i)
    {
        cin>>AA.x>>AA.y>>BB.x>>BB.y;
        det(AA,BB);
    }
    return 0;
}
