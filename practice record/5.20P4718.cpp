#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll x,y,a[N];
ll max_factor;
struct big_interger_factor
{
    const static int N = 1e6 + 7;
    ll prime[N],p[N],fac[N],sz,cnt;
    inline ll mul(ll a,ll b,ll mod)
    {
        if(mod < 1000000000)
        {
            return a * b % mod;
        }
        return (a * b - (ll)((long double)a / mod * b + 1e-8) * mod + mod) % mod;
    }
    void init(int maxn)
    {
        int tot = 0;
        sz = maxn - 1;
        for(int i = 1;i <= sz;++i)
            p[i] = i;
        for(int i = 2;i <= sz;i++)
        {
            if(p[i] == i)
            {
                prime[tot++] = i;
            };
            for(int j = 0;j < tot && 1ll * i * prime[j] <= sz;++j)
            {
                p[i * prime[j]] = prime[j];
                if(i % prime[j] == 0)
                {
                    break;
                }
            }
        }
    }
    ll qpow(ll a,ll x,ll mod)
    {
        ll res = 1;
        while(x)
        {
            if(x & 1)
            {
                res = mul(res,a,mod);
            }
            a = mul(a,a,mod);
            x >>= 1;
        }
        return res;
    }
    bool check(ll a,ll n)
    {
        ll t = 0,u = n - 1;
        while(!(u & 1))
        {
            t++,u >>= 1;
        }
        ll x = qpow(a,u,n),xx = 0;
        while(t--)
        {
            xx = mul(x,x,u);
            if(xx == 1 && x != 1 && x != n - 1)
                return false;
            x = xx;
        }
        return xx == 1;
    }
    bool miller(ll n,int k)
    {
        if(n == 2)
        {
            return true;
        }
        if(n < 2 || !(n & 1))
            return false;
        if(n <= sz)
            return p[n] == n;
        for(int i = 0;i <= k;++i)
        {
            if(!check(rand() % (n - 1) + 1,n))
                return false;
        } 
        return true;
    }
    inline ll gcd(ll a,ll b)
    {
        return b == 0 ? a : gcd(b,a % b);
    }
    inline ll Abs(ll a)
    {
        return x < 0 ? -x : x;
    }
    ll Pollard_rho(ll n)
    {
        ll s = 0,t = 0,c = rand() % (n - 1) + 1,v = 1,ed = 1;
        while(1)
        {
            for(int i = 1;i <= ed;++i)
            {
                t = (mul(t, t, n) + c) %  n;
                v = mul(v,Abs(t - s),n);
                if(i % 127 == 0)
                {
                    ll d = gcd(v,n);
                    if(d > 1)
                        return d;
                }
            }
            ll d = gcd(v,n);
            if(d > 1)
                return  d;
            s = t;
            v = 1;
            ed <<= 1;
        }
    }
    void get_factor(ll n)
    {
        if(n <= sz)
        {
            while(n != 1)
            {
                fac[cnt++] = p[n],n /= p[n];
                max_factor = max(max_factor,p[n]);
            }
            return ;
        }
        if(miller(n, 6))
        {
            fac[cnt++] = n;
            max_factor = max(max_factor,p[n]);
        }else 
        {
            ll d = n;     
            while(d >= n)
            {
                d = Pollard_rho(n);
            }
            get_factor(d);
            get_factor(n / d);
        }
        return;
    }
}Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll T,n;
    Q.init(N-1);
    cin >> T ;
    while(T--)
    {
        max_factor = -1;
        cin >> n;
        Q.get_factor(n);
        if(max_factor == n || max_factor == 1)
            cout << "Prime" << '\n';
        else 
            cout << max_factor << '\n';
    }
}