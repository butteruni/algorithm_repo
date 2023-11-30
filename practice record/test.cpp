#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int qpow(ll a,ll b,ll mod)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    n -= 4;
    ll ans = 0;

    for(int i = 1;i * i<= n;++i)
    {
        if(n % i == 0)
        {
            ans += i;
            ans += n / i;
        }
    }
    cout << ans << '\n';
}