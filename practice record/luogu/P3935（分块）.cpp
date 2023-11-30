#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll calc(ll n)
{
    ll res = 0;
    for(ll l = 1,r;l <= n;l = r + 1)
    {
        r = n / (n / l);
        res = (res + ((r - l + 1) % mod) * ((n / l) % mod)) % mod;
    }
    return res;
}
int main()
{
    ll l,r,sum1 = 0,sum2 = 0;;
    cin >> l >> r;
    // 计算 \sum_{i = 1}^{n} \floor{k / i}
    sum1 = calc(r);
    sum2 = calc(l - 1);
    cout << ((sum1 - sum2) % mod + mod) % mod; 
}