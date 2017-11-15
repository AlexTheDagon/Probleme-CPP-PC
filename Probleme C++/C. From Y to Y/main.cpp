#include <iostream>

using namespace std;
int k,fr;
int main()
{
    cin>>k;
    for (int i=0;i<26;i++)
    {
        fr=1;
        while((fr+1)*fr/2<=k)++fr;
        k-=fr*(fr-1)/2;
        for(int j=0;j<fr;++j)cout<<(char)('a'+i);
    }
    return 0;
}
///editorial
