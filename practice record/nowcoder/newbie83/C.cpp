#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
double p = 1.0;
double qpow(double a,int b)
{
    double res = 1.0;
    while(b)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
void solve()
{
    double a,b,c;
    cin >> a >> b >> c;
    a /= 16.0,b /= 16.0,c /= 16.0;
    double d = 1.0 - a - b - c;
    double ans = 0;
    ans += qpow(a,16);
    ans += qpow(a,12) * qpow(b,4) * p;
    ans += qpow(a,12) * qpow(c,4) * p;


    cout << fixed << setprecision(12) << ans << '\n';

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i <= 12;++i)
    {
        p *= (16 - i + 1);
        p /= (double)i;
    }
    while(t--)
    {
        solve();
    }
}