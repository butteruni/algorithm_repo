#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long ll;
ll n,q,k;
ll a[N],pre[N],mn[N];
bool check(ll x)
{
    ll pos = lower_bound(a + 1,a + 1 + n,x) - a;
    if(mn[max(pos - 1,1ll)] + k < x)
    {
        return 0;
    }
    if(pos == 1)
    {
        return 1;
    }
    if(pos > k + 1)
    {
        return 0;
    }
    if(pos == n + 1 && !(n % 2 == k % 2))
    {
        return 0;
    }
    ll res = k - (pos - 1) - 2 * ((pos - 1) * (k - x) + pre[pos - 1]);
    if(pos == n + 1)
    { 
        return res <= 0;
    }
    if(res <= 0 || res % 2 == 1)
        return 1;
    if(n - (pos - 1) >= 2)
        return 1;
    if(a[n] - res / 2 >= x)
        return 1;
    return 0;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;++i)
    {
        mn[i] = a[i] - i + 1;
        pre[i] = pre[i - 1] + mn[i];
    }
    for(int i = 2;i <= n;++i)
        mn[i] = min(mn[i - 1],mn[i]);
    // k = 1;
    // cout << check(2) << endl;
    for(int i = 1;i <= q;++i)
    {
        cin >> k;
        if(n == 1)
        {
            if(k % 2 == 0)
                cout << a[1] - k / 2 << ' ';
            else 
                cout << a[1] + k - (k - 1) / 2 << ' ';
        }else
        {
            ll l = 1,r = 1e12;
            while(l < r)
            {
                ll mid = (l + r + 1) >> 1;
                if(check(mid))
                {
                    l = mid;
                }else 
                {
                    r = mid - 1;
                }
            }
            cout << l << ' ';
        }
    }
}