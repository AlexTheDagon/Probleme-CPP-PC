#include <iostream>
#include <fstream>
using namespace std;
ifstream in("joben.in");
ofstream out("joben.out");
string s1,s2;
int t,fr1[300],fr2[300],sem;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>s1>>s2;
        sem=1;
        for(auto i:s1)++fr1[i];
        for(auto i:s2)++fr2[i];
        for(int i='a';i<='z';++i)
            for(int j='a';j<='z';++j)if(fr1[i]==fr2[j])fr1[i]=fr2[j]=0;
        for(int i='a';i<='z';++i)if(fr1[i])sem=0;
        if(sem)out<<"DA";
        else out<<"NU";
        out<<'\n';
        for(int i='a';i<='z';++i)fr1[i]=fr2[i]=0;
    }
    return 0;
}
