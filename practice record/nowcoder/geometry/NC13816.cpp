//https://ac.nowcoder.com/acm/problem/13816
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x > 0) return 1;
    return 2;
}
double area(double x)
{
    return x * x * pi;
}
int t;
int main()
{
    cin >> t;
    while(t--)
    {
        double a,b,c;
        cin >> a >> b >> c;
        double mins = min(a,min(b,c));
        double mx = max(a,max(b,c));
        double mid = a + b + c - mins - mx;
        double ans = 0;
        ans += area(mid) + area(mx - mid);
        cout << ans << '\n';
    }
}