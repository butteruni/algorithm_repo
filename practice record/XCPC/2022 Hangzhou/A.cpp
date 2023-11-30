#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll k=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    vector<ll>A(n);
    ll sum = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> A[i];
        sum += A[i];
    }
    ll k = (1ll + n) * n / 2;
    sum %= m;
    ll a = n;
    ll b = k;
    ll x,y;
    ll d = exgcd(a,b,x,y);
    ll xx,yy;
    ll g = exgcd(d,m,xx,yy);
    ll cnt = (m - sum + g - 1) / g;
    ll ans1 = (cnt * xx % m) * x % m;
    ll ans2 = (cnt * xx % m) * y % m;
    cout << (g * cnt + sum) % m << "\n";
    cout << (ans1 + m) % m << " " << (ans2 + m) % m << "\n";

}