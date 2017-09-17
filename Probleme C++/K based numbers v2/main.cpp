#include <iostream>

using namespace std;
int n,k,s0[4000],s1[4000],s[4000];
void transfer(int A[], int B[])
{
    int l=max(A[0],B[0])+1;
    for(int i=0;i<=l;++i)
    {
        A[i]=B[i];
    }
}
void add(int A[], int B[])
{
      int i,t=0;
      for(i=1 ; i<=A[0] || i<=B[0] || t; i++, t/=10)
              A[i] = (t += A[i] + B[i]) % 10;
      A[0] = i - 1;
}
void mul(int A[], int B)
{
      int i, t = 0;
      for (i = 1; i <= A[0] || t; i++, t /= 10)
              A[i] = (t += A[i] * B) % 10;
      A[0] = i - 1;
}
int main()
{
    cin>>n>>k;
    s1[1]=k-1;
    s1[0]=1;
    s0[0]=1;
    for(int i=2;i<=n;++i)
    {
        transfer(s,s0);
        transfer(s0,s1);
        add(s1,s);
        mul(s1,(k-1));
    }
    add(s1,s0);
    for(int i=s1[0];i>=1;--i)cout<<s1[i];
    return 0;
}
