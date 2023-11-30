#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6 + 10,mod = 998244353,g = 3,invg = 332748118;
ll r[N],inv[N],a1[N],a2[N],fac[N];
int len;
vector<ll> A,B,C;
void init()
{
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2;i <= 100000;++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for(int i = 2;i <= 100000;++i)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void NTT(ll *A,int type)
{
    for(int i = 0;i < len;++i)
    {
        if(i < r[i])
        {
            swap(A[i],A[r[i]]);
        }
    }
    for(int mid = 1;mid < len;mid <<= 1)
    {
        ll wn = 0;
        if(type == 1)
        {
            wn = qpow(g,(mod - 1) / (mid << 1));
        }else 
        {
            wn = qpow(invg,(mod - 1) / (mid << 1));
        }
        for(int i = 0;i < len;i += (mid << 1))
        {
            ll w0 = 1;
            for(int j = 0;j < mid;++j,w0 = 1ll * w0 * wn % mod)
            {
                ll x = A[i + j], y = w0 * A[i + j + mid] % mod;
                A[i + j] = (x + y) % mod;
                A[i + j + mid] = (x - y + mod) % mod;
                // cout << y << "|";
            }
        }
    }
}
vector <ll> poly_mul(const vector<ll>&A, const vector<ll>&B) //封装好的NTT模板
{
    int n1 = A.size() - 1,n2 = B.size() - 1;
    vector<ll> res(n1 + n2 + 1);
    if(n1 <= 50 && n2 <= 50)
    {
        for(int i = 0;i <= n1;++i)
        {
            for(int j = 0;j <= n2;++j)
                res[i + j] = (res[i + j] + 1ll * A[i] * B[j]) % mod;
        }
        return res;
    }
    len = 1;
    int l = 0;
    while(len <= n1 + n2)
    {
        len <<= 1;
        l++;
    }
    for(int i = 1;i < len;++i)
    {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for(int i = 0;i < len;++i)
    {
        if(i <= n1)
            a1[i] = A[i];
        else 
            a1[i] = 0;
        if(i <= n2)
            a2[i] = B[i];
        else 
            a2[i] = 0;
    }
    NTT(a1,1);
    NTT(a2,1);
    for(int i = 0;i < len;++i)
    {
        a1[i] = a1[i] * a2[i] % mod;
    }
    NTT(a1,-1);
    ll inv = qpow(len,mod-2);
    for(int i = 0;i < len;++i)
        a1[i] = a1[i] * inv % mod;
    for(int i = 0;i <= n1 + n2;++i)
        res[i] = a1[i];
    return res;
}
vector <ll> solve(int l,int r)
{
    if(l == r)
    {
        vector <ll>res;
        res.push_back(C[l]);
        res.push_back(B[l]);
        return res;
    }
    int mid = l + r >> 1;
    return poly_mul(solve(l,mid),solve(mid + 1,r));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t--)
    {
        int n;
        cin >> n;
        A = vector<ll>(n + 1);
        B = vector<ll>(n - 1);       
        C = vector<ll>(n - 1);
        for(int i = 0;i <= n;++i)
        {
            cin >> A[i];
            A[i] = A[i] * fac[i] % mod;
        }
        for(int i = 0;i <= n - 2;++i)
            cin >> B[i];
        for(int i = 0;i <= n - 2;++i)
            cin >> C[i];
        vector<ll> G = solve(0,n-2);
        reverse(A.begin(),A.end());
        vector<ll>ans = poly_mul(G,A);
        for(int i = 0;i < n;++i)
        {
            cout << ((ans[n - i] * inv[i] + mod) + mod)% mod << ' ';
        }
        cout << (ans[0] * inv[n] + mod) % mod << '\n';
    }
    return 0;
}