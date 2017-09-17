#include <iostream>

using namespace std;
int s,d[]={1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1},aux;
long long nr;
int main()
{
    cin>>s;
    if(s==1)cout<<"10";
    else
    {
        for(int i1=0;i1<10;++i1)
        {
            for(int i2=0;i2<10;++i2)
            {
                for(int i3=0;i3<10;++i3)
                {
                    for(int i4=0;i4<10;++i4)
                    {
                        for(int i5=0;i5<10;++i5)
                        {
                            for(int i6=0;i6<10;++i6)
                            {
                                for(int i7=0;i7<10;++i7)
                                {
                                    aux=s-i1-i2-i3-i4-i5-i6-i7;
                                    if(aux>=0 && aux<19)nr=nr+d[aux];
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<nr;
    }
    return 0;
}
