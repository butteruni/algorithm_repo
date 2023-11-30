#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 510;
ll cnt_son[N],fac[N],cnt[N],inv_fac[N];
int sz[N];
ll dp[N][N];
vector<int>e[N];
ll f[N][N];
ll g[N];
int n;
void dfs1(int u,int pa)
{
    cnt_son[u] = 0;
    sz[u]++;
    cnt[u] = 1;
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dfs1(x,u);
        cnt_son[u]++;
        sz[u] += sz[x];
        cnt[u] = cnt[u] * cnt[x] % mod;
    }
    cnt[u] = cnt[u] * fac[cnt_son[u]] % mod;
}
void dfs2(int u,int pa)
{
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    for(auto x : e[u])
    {
        if(x == pa)
            continue;
        for(int i = cnt_son[u];i >= 1;--i) // 计算 f_{i,j} 方案数
        {
            for(int j = sz[u] - 1;j >= sz[x];--j)
                f[i][j] = (f[i][j] + f[i - 1][j - sz[x]]) % mod;
        }
    }
    for(auto v:e[u])
    {
        if(v == pa)
            continue;
        for(int i = 1;i <= cnt_son[u];++i) // 计算 f_{i,j}扣除元素v的 方案数
        {
            for(int j = sz[v];j <= sz[u] - 1;++j)
                f[i][j] = (f[i][j] - f[i - 1][j - sz[v]] + mod) % mod;
        }
        for(int i = 0;i < cnt_son[u];++i)
        {
            for(int j = 0;j <= sz[u] - sz[v] - 1;++j)
                g[j] = (g[j] + (f[i][j] * fac[i] % mod) * fac[cnt_son[u] - i - 1]) % mod; 
        }
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j < i;++j)
            {
                dp[v][i] = (dp[v][i] + (dp[u][j] * g[i - j - 1] % mod + mod)* inv_fac[cnt_son[u]] % mod + mod) % mod;
            }
        }
        for(int i = 0;i <= n;++i)
            g[i] = 0;
        for(int i = cnt_son[u];i >= 1;--i)// 把扣的补回去
        {
            for(int j = sz[u] - 1;j >= sz[v];--j)
                f[i][j] = (f[i][j] + f[i - 1][j - sz[v]] ) % mod;
        }
    }
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dfs2(x,u);
    }
}
ll qpow(ll a, ll b)
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
    fac[0] = 1;
    
    for(ll i = 1;i <= 500;++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        // cout << fac[i] <<"  ";
    }
    inv_fac[500] = qpow(fac[500], mod - 2);
    for(int i = 499;i >= 0;--i)
    {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
    // cout << inv_fac[1] << " ";
    cin >> n;
    for(int i = 1;i < n;++i)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dp[1][1] = cnt[1];
    dfs2(1,0);
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}