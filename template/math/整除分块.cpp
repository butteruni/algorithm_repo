#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
// 计算\sum_{i = 1}^{n} \floor{n / i} 根据实际情况更改计算公式
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
    ll n,k,ans=0;
    cin >> n >> k;
    // 计算 \sum_{i = 1}^{n} \floor{k / i}
    for(ll l=1,r;l<=n;l=r+1)
    {
        if(k / l != 0)
        {
            r = min(k / (k / l),n);
        }
        else 
        {
            r = n;
        }
        ans += (r - l + 1) * (k / l);
    }
    cout << ans;     
}