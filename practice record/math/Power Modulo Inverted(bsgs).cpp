#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,z,k;
int gcd(int a,int b)
{
    if(b == 0)
        return a;
    else 
        return gcd(b,a % b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b == 0)
    {
        x = 1,y = 0;
        return;
    }
    ll t;
    exgcd(b, a % b,x,y);
    t = x,x = y;
    y = t - a / b * y;
}
ll inv(ll a,ll b)
{
    ll x = 0,y = 0;
    exgcd(a,b,x,y);
    return (x % b + b) % b;
}
ll qpow(ll a,ll b,ll mod)
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
int bsgs(ll a,ll b,ll p)
{
    if(p == 1)
        return 0;
    a %= p,b %= p;
    if(b == 1)
        return 0;
    int m = ceil(sqrt(p)),i = 0;
    ll t = qpow(a,m,p);
    map<ll,ll>mp;
    mp.clear();
    for(ll j = b;i < m;++i,j = j * a % p)
    {
        mp[j] = i;
    }
    i = 1;
    for(ll j = t;i <= m;i++,j = j * t % p)
    {
        if(mp.count(j))
            return i * m - mp[j];
    }
    return -1;
}
ll exbsgs(ll a,ll b,ll p)
{
    if(p == 1)
        return 0;
    a %= p,b %= p;
    if(b == 1)
        return 0;
    int x = 0,t,ans;
    ll y = 1;
    while((t = gcd(a,p)) != 1)
    {
        if(b % t != 0)
        {
            return -1;
        }
        b /= t,p /= t;
        x++;
        y = y * (a / t) % p;
        if(b == y)
            return x;
    }
    // cout << a << " " << b << endl;
    ans = bsgs(a, b * inv(y,p) % p,p);
    if(ans == -1)
        return -1;
    return ans + x;
}
int main()
{
    while(cin >> x >> z >> k)
    {
        if(x == 0)
            break;
        ll ans = exbsgs(x,k,z);
        // cout << ans << endl;
        if(ans == -1)
            cout << "No Solution\n";
        else 
            cout << ans << "\n";
    }
}