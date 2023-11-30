#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-7; 
bool check(double x)
{
    return (x - (ll)x) == 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        map<ll,ll>cnt;
        int n;
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            ll x;
            cin >> x;
            cnt[x]++;
        }
        int q;
        cin >> q;
        while(q--)
        {
            ll k1,k2;
            cin >> k1 >> k2;
            ll delta = k1 * k1 - 4 * k2;
            if(delta >= 0)
            {
                ll d = sqrt(delta);
                long long k = d;
                // cout << d << " " << k << " ";
                if(k == d && d * d == delta)
                {
                    ll x1 = (k1 - k) / 2,x2 = (k1 + k) / 2;
                    if(x1 == x2)
                    {
                        cout << (cnt[x1] * (cnt[x1] - 1)) / 2 << " ";
                    }else 
                    {
                        cout << cnt[x1] * cnt[x2] << " ";
                    }
                }else 
                {
                    cout << 0 << ' ';
                }
            }else 
            {
                cout << 0 << " ";
            }
        }
        cout << '\n';
    }
}