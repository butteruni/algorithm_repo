#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
ll e[N << 1],ne[N << 1],h[N],idx;
ll sz[N];
ll fac[N],inv[N];
ll ans;
int n,k;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = inv[0] = 1;
    for(int i = 1;i <= n;++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n] = qpow(fac[n],MOD - 2);
    for(int i = n - 1;i >= 1;--i)
        inv[i] = inv[i + 1] * (i + 1) % MOD; 
}
ll C(ll a,ll b)
{
    if(a < 0 || a < b || b < 0)
        return 0;
    return (fac[a] * inv[b] % MOD) * inv[a - b] % MOD;
}
void dfs(int cur,int fa)
{
    sz[cur] = 1;
    for(int i = h[cur];i != - 1;i = ne[i])
    {
        int j = e[i];
        if(j == fa)
            continue;
        dfs(j,cur);
        sz[cur] += sz[j];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof(h));
    cin >> n >> k;
    init();
    for(int i = 1;i < n;++i)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    
    if(k & 1)
        cout << 1 << endl;
    else
    {
        dfs(1,0);
        for(int i = 1;i <= n;++i)
        {
            ans = (ans + C(sz[i],k / 2) * C(n - sz[i], k / 2)) % MOD;
        }
        ans = (ans * qpow(C(n,k),MOD - 2) % MOD);
        ans += 1;
        cout << (ans + MOD) % MOD << endl;
    }

}