#include <iostream>

using namespace std;
string a,b;
int nr,sem,da[150];
char nou[150],c;
int main()
{
    cin>>a>>b;
    for(int i=0;i<a.size();++i)
    {

        if((isalpha(nou[a[i]]) && b[i]!=nou[a[i]])||(isalpha(nou[b[i]]) && a[i]!=nou[b[i]]))sem=1;
        if(a[i]!=b[i] && !isalpha(nou[a[i]]) && !isalpha(nou[b[i]]))
        {
            da[a[i]]=1;
            ++nr;
        }
        nou[a[i]]=b[i];
        nou[b[i]]=a[i];
    }
    if(sem)cout<<"-1";
    else
    {
        cout<<nr<<'\n';
        for(int i=0;i<150;++i)
        {
            if(da[i])
            {
                cout<<char(i)<<" "<<nou[i]<<'\n';
                nou[nou[i]]='1';
            }
        }

    }
    return 0;
}
