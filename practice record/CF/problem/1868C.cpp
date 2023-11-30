#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1e5 + 10;
const int M = 110;
ll cnt[N][M];
ll cnt_inv[N][M];
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
    for(int i = 1;i < N;++i)
    {
        cnt[i][0] = 1;
        for(int j = 1;j < M;++j)
            cnt[i][0] = cnt[i][j - 1] * i;
        cnt_inv[i][M - 1] = qpow(cnt[i][M - 1],mod - 2);
        for(int j = M - 2;j >= 0;--j)
            cnt_inv[i][j] = cnt_inv[i][j + 1] * i % mod;
    }
}
ll n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        


    }
}