#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
const ll mod = 998244353;
ll ans;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b & 1)
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
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
}