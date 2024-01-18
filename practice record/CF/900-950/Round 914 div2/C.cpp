#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e3 + 10;
ll a[N];
void solve()
{
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    a[n + 1] = (ll)1e19;
    a[0] = 0;
    if(k >= 3)
    {
        cout << 0 << '\n';
    }else if(k == 1)
    {
        ll mn = 1e18;
        for(int i = 1;i < n;++i)
            mn = min(mn,a[i + 1] - a[i]);
        mn = min(a[1],mn);
        cout << mn << '\n';
    }else if(k == 2)
    {
        ll mn = 1e18;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j < i;++j)
            {
                ll gap = a[i] - a[j];
                int l = lower_bound(a + 1,a + 1 + n,gap) - a;
                if(l != 1)
                {
                    mn = min(mn,abs(gap - a[l]));
                    l -- ;
                    mn = min(mn,abs(gap - a[l]));
                }else 
                {
                    mn = min(mn,abs(gap - a[l]));

                }
                mn = min(mn,gap);

            }
            // mn = min(mn,min(abs(gap - a[l]),abs(gap - a[r])));
        }
        mn = min(mn,a[1]);
        cout << mn << '\n';
    }else if(k == 0)
    {
        cout << a[1] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}