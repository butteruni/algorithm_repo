#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NR = 1 << 22;
const double eps = 1e-6, pi = acos(-1.0);
complex <double> a[NR],b[NR];
int n,m;
void FFT(complex<double> *a, int n,int inv)
{
    if(n == 1)
        return;
    int mid = n / 2;
    complex<double> A1[mid + 1],A2[mid + 1];
    for(int i = 0;i <= n;i += 2)
    {
        A1[i / 2] = a[i];
        A2[i / 2] = a[i + 1];
    }
    FFT(A1,mid,inv);
    FFT(A2,mid,inv);
    complex<double> w0(1,0), wn(cos(2 * pi / n),inv * sin(2 * pi / n));
    for(int i = 0;i < mid; ++i,w0 *= wn)
    {
        a[i] = A1[i] + w0 * A2[i];
        a[i + n / 2] = A1[i] - w0 * A2[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for(int i = 0;i <= n;++i)
    {
        double x;
        scanf("%lf", &x);
        a[i].real(x);
    }
    for(int i = 0;i <= m;++i)
    {
        double x;
        scanf("%lf", &x);
        b[i].real(x);
    }
    int len = 1 << max((int)ceil(log2(n + m)), 1);
    FFT(a, len , 1);
    FFT(b, len , 1);
    for(int i = 0;i <= len; ++i)
    {
        a[i] = a[i] * b[i];
    }
    FFT(a,len,-1);
    for(int i = 0;i <= n + m;++i)
        printf("%.0f ",a[i].real() / len + eps);
    return 0;
}