#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int t;
ll x[N];
ll k,n,m;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res =res * a;
        }
        a =a * a ;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;++i)
        cin >> x[i];
    
}