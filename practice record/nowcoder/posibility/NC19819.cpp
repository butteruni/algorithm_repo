#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1010;
ll dp[15][N][N],inv[N],fac[N];
ll cnt[N];
ll qpow(ll a,ll b)
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
void init()
{
    inv[1] = 1,fac[0] = 1;
    for(int i = 2;i <= 1000;++i)
    {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for(ll i = 1;i <= 1000;++i)
    {
        fac[i] = i * fac[i - 1] % mod;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    init();
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>q(n + 1);
        ll Q = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> q[i];
            Q += q[i];
        }
        memset(dp,0,sizeof(dp));
        ll inv_Q = qpow(Q, mod - 2);
        vector<ll>c(n + 1);
        ll up = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> c[i];
            up += c[i];
        }
        // for(int i = 0;i < n;++i)
            // q[i] = q[i] * inv_Q % mod;
        dp[0][0][0] = 1;
        for(int i = 0; i < n;++i)
        {
            cnt[0] = 1;
            for(int j = 1;j < up * 4;j++)
                cnt[j] = cnt[j - 1] * inv[j] % mod * q[i + 1] % mod * inv_Q % mod;
            for(int j = 0;j < up * 4;++j)
            {
                for(int k = 0;k < up * 4;++k)
                {
                    if(dp[i][j][k])
                    {
                        for(int jj = 0;j + jj < up * 4;++jj)
                        {
                            int kk;
                            if(jj > c[i + 1])
                                kk = c[i + 1] * 3 + jj;
                            else 
                                kk = jj * 4;
                            if(kk + k < up * 4)
                                dp[i + 1][j + jj][k + kk] = (dp[i + 1][j + jj][k + kk] + dp[i][j][k] * cnt[jj]) % mod;

                        }
                    }
                }
            }
        }
        ll ans = 0;
        for(int j = 0;j < up * 4;j ++)
        {
            for(int k = 0;k < up * 4;++k)
                if(dp[n][j][k])
                {
                    ans = (ans + dp[n][j][k] * fac[j]) % mod;
                }
        }
        cout << ans << '\n';
    }
}