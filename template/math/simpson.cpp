// https://ac.nowcoder.com/acm/problem/15403
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
double a[N],b[N],k[N];
double ans[N];
int n;
double square(double x)
{
    return x * x;
}
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt(square(x1 - x2) + square(y1 - y2));
}
double f(double x) //函数自行修改
{
    double mins = 100.0;
    int temp = 0;
    for(int i = 1;i <= n;++i)
    {
        double y = k[i] * square(x - a[i]) + b[i];
        if(y < mins)
        {
            mins = y;
            temp = i;
        }
    }
    double t = 2 * k[temp] * (x - a[temp]);
    return sqrt(t * t + 1.0);
}
double simpson(double x,double y)
{
    double mid = (x + y) / 2;
    return (f(x) + 4 * f(mid) + f(y)) * (y - x) / 6;
}
double asr(double l,double r,double depth,double eps,double S)
{
    double mid = (l + r) / 2;
    double ls = simpson(l, mid);
    double rs = simpson(mid, r);
    if(depth >= 10 && fabs(ls + rs - S) <= 15 * eps)
        return ls + rs + (ls + rs - S) / 15.0;
    return asr(l,mid,depth + 1,eps / 2,ls) + asr(mid,r,depth + 1,eps / 2,rs);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> k[i] >> a[i] >> b[i];
    }
    printf("%.2lf\n",asr(0,100,0,1e-6,simpson(0, 100)));
}