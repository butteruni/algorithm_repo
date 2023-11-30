#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll ans = 1;
    for(ll i = 1;i < n;++i)
    {   
        if(s[i] == '?')
            ans = ans * i % mod;
    }  
    if(s[0] == '?')
    {
        cout << 0 << "\n";
    } else 
    {
        cout << ans % mod << '\n';
    }
    for(int i = 1;i <= m;++i)
    {
        int pos;
        char x;
        cin >> pos >> x;
        pos--;
        if(pos && s[pos] == '?')
        {
            ans = ans * qpow(pos,mod - 2) % mod;
        }
        s[pos] = x;
        if(pos && x == '?')
        {
            ans = ans * pos % mod;
        }
        if(s[0] == '?')
        {
            cout << 0 << '\n';
        }else 
        {
            cout << ans << '\n';
        }
    }
}