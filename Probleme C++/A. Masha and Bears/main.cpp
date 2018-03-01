#include <iostream>

using namespace std;
int sem,v[4],m;
int main()
{
    for(int i=1;i<4;++i)cin>>v[i];
    cin>>m;
    for(int i=v[3];i<=2*v[3];++i)
        for(int j=v[2];j<=2*v[2];++j)
            for(int k=v[1];k<=2*v[1];++k)
                if(m<=i && 2*m>=i && i<j && j<k && 2*m<j)
                {
                    cout<<k<<" "<<j<<" "<<i;
                    return 0;
                }
    cout<<"-1";
    return 0;
}
