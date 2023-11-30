#include <bits/stdc++.h>
typedef long long ll;
const int N = 4000000 + 100, g = 3, invg = 332748118, mod = 998244353;
//998244353的一个原根为3且998244353-1=2^23*119，3在模998244353意义下的逆元为332748118
using namespace std;
int n, m, r[N]; //rev[i]为i的二进制翻转
long long a[N], b[N];
ll qpow(ll a, ll k) //快速幂，a为底数，k为指数
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
void NTT(ll *a,int type,int len)
{
    for(int i = 0;i < len;++i)
        if(i < r[i])
            swap(a[i],a[r[i]]);
    for(int mid = 1;mid < len;mid <<= 1)
    {
        ll wn = 1;
        if(type == 1)
            wn = qpow(g,(mod - 1) / (mid << 1));
        else
            wn = qpow(invg,(mod - 1) / (mid << 1));
        for(int i = 0;i < len;i += (mid << 1))
        {
            for(int j = 0,w0 = 1;j < mid;++j,w0 = 1ll * w0 * wn % mod)
            {
                ll x = a[i + j], y = w0 * a[i + j + mid] % mod;
                a[i + j] = (x + y) % mod;
                a[i + j + mid] = (x - y + mod) % mod; 
            }
        }
    }
}
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    // cout << s1 << endl << s2 << endl;
    n = s1.length() - 1;
    m = s2.length() - 1;
    for(int i = 0;i <= n;++i)
        a[i] = s1[n - i] - '0';
    for(int i = 0;i <= m;++i)
        b[i] = s2[m - i] - '0';
    int len = 1 << max((int)ceil(log2(n + m)), 1);
    for(int i = 0;i < len;++i)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (max((int)ceil(log2(n + m)), 1) - 1));
    NTT(a,1,len),NTT(b,1,len);
    for(int i = 0;i < len;++i)
        a[i] = a[i] * b[i] % mod;
    NTT(a,-1,len);
    ll inv = qpow(len,mod-2);
    for (int i = 0; i <= len; i++)
        a[i] = a[i] * inv % mod;
    for (int i=0; i < len; i++)
    {
        if (a[i]>=10) 
        {
            a[i+1] += a[i] / 10; 
            a[i] %= 10;
        }
    }
    while(!a[len] && len) len--;
    while(a[len] >= 10)
    {
        a[len + 1] += a[len] / 10;
        a[len++] %= 10;
    }
    for(int i = len;i >= 0;--i)
        cout << a[i];
    return 0;	
}