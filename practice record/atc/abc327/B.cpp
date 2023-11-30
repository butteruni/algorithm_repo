#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll b;
    bool ok = 0;
    cin >> b;
    for(ll i = 1;i <= 15;++i)
    {
        ll ans = qpow(i,i);
        if(ans > b)
            break;
        if(ans == b)
        {
            cout << i << '\n';
            ok = 1;
            break;
        }
    }
    if(!ok)
    {
        cout << -1 << '\n';
    }
}