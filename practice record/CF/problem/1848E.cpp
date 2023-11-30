#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q >> m;
    vector<ll>x(q);
    for(int i = 1;i <= q;++i)
    {
        cin >> x[i - 1];
    }
}   