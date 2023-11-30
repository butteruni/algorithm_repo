#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  N = 2e5 + 10;
ll a[N];
ll n,q;
bool check(ll len,ll val)
{
    ll res = 0;
    for(int i = 1;i <= len;++i)
        res += a[i];
    // cout << res << "||" << len  << "==" << val << " ";
    if(res + len == val)
        return 1;
    for(int r = len + 1;r <= n;++r)
    {
        res += a[r];
        res -= a[r - len];
        if(res + len == val)
            return 1;
    }
    // cout << res << " ";
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        ll sum = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            a[i]--;
            // sum += a[i];
        }
        for(int i = 1;i <= q;++i)
        {
            int op;
            cin >> op;
            if(op == 1)
            {
                ll x;
                cin >> x;
                bool ok = 0;
                for(int len = x / 2 - 1;len <= min(x,n);++len)
                {
                    if(check(len,x))
                    {
                        ok = 1;
                        break;
                    }
                }
                if(!ok)
                {
                    cout << "NO\n";
                }else 
                {
                    cout << "YES\n";
                }
            }else 
            {
                ll pos,x;
                cin >> pos >> x;
                a[pos] = x;
                a[pos]--;
            }
        }
    }
}