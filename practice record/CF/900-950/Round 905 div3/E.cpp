#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n);
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        ll ans = 0;
        if(n == 1)
        {
            cout << ans << '\n';
        }else 
        {
            ll cnt = 0;
            for(int i = 1; i < n; ++i)
            {
                ll tl = a[i - 1], tr = a[i];
                if(tl > tr)
                {
                    ll tmp = 0;
                    while(tl > tr)
                    {
                        tr *= 2;
                        tmp++;
                    }
                    cnt += tmp;
                }else if(tl < tr)
                {
                    ll tmp = 0;
                    while(tl < tr)
                    {
                        tl *= 2;
                        tmp++;
                    }
                    if(a[i - 1] * 1ll << tmp > a[i])
                    {
                        cnt++;
                    }
                    cnt = max(0ll, cnt - tmp);
                }
                ans += cnt;
            }
            cout << ans << '\n';
        }
    }
}