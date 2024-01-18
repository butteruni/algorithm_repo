#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double qpow(double a,ll b)
{
    double res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
ll n;
ll l,r;
double p;

int main()
{
    cin >> n >> p >> l >> r;
    double exp = 1.0 / p;
    cout << fixed << setprecision(12)  << (r / exp) - ((l - 1) / exp) << '\n';
}