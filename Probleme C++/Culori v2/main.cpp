#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
int n;
int a[10000];
int b[10000];
int nr[10000];
void mul(int A[], int B)
{
      int i, t = 0;
      for (i = 1; i <= A[0] || t; i++, t /= 10)
              A[i] = (t += A[i] * B) % 10;
      A[0] = i - 1;
}
void divide(int A[], int B)
{
      int i, t = 0;
      for (i = A[0]; i > 0; i--, t %= B)
              A[i] = (t = t * 10 + A[i]) / B;
      for (; A[0] > 1 && !A[A[0]]; A[0]--);
}
int main()
{
    in>>n;
    if(n==1)out<<"5";
    else
    {
        a[0]=1;
        a[1]=8;
        for(int i=2;i<=n/2;++i)mul(a,3);
        if(n%2==1)
        {
            mul(a,7);
            divide(a,4);
        }
        for(int i=a[0];i>0;--i)out<<a[i];

    }
    return 0;
}
