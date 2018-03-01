#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k,sol=0;
int main()
{
    cin>>k;
    if(k==0)
    {
        cout<<"1";
        return 0;
    }
    if(k>36)cout<<"-1";
    else
    {
        while(k>1)
        {
            cout<<"8";
            k-=2;
        }
        if(k)cout<<"9";
    }
    return 0;
}
