#include <iostream>
#include <algorithm>
using namespace std;
string ol,ig;
char nou[1000000];
int indig,indol,st,fn,fnol,stig;
int main()
{
    cin.sync_with_stdio(false);
    cin>>ol>>ig;
    sort(ol.begin(),ol.end());
    sort(ig.begin(),ig.end());
    fn=ig.size()-1;
    indig=fn;
    fnol=(fn+1)/2;
    stig=fn/2;
    for(int i=0;i<ol.size();++i)
    {
        if(i%2)
        {
            if(ig[indig]>=ol[indol])nou[st++]=ig[indig--];
            else nou[fn--]=ig[stig++];
        }
        else
        {
            if(ig[indig]>ol[indol])nou[st++]=ol[indol++];
            else nou[fn--]=ol[fnol--];
        }
    }
    for(int i=0;i<ol.size();++i)cout<<nou[i];
    return 0;
}
