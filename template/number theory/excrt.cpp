#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e18;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) 
{
    if (!b) d = a, x = 1, y = 0;
    else exgcd(b, a % b, d, y, x), y -= x * (a / b);
}

pll excrt(pll l, pll r) 
{
    auto[r1, m1] = l;
    auto[r2, m2] = r;
    if (r1 == -1 || r2 == -1) return {-1, -1};
    ll d, l1, l2;
    exgcd(m1, m2, d, l1, l2);
    if ((r2 - r1) % d) return {-1, -1};
    ll L = m1 * m2 / d;
    ll R = ((r1 + (r2 - r1) / d * l1 % L * m1) % L + L) % L;
    return {R, L};
}