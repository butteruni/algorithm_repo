#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>cnt;
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
        cnt.clear();
        vector<ll>a(n);
        ll ans = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }   
        for(auto [x,val]:cnt)
        {
            ans = ans + (val - 1) * val / 2;
            for(ll i = 1;(1 << i) <= x;++i)
            {
                ll b = x - i;
                if(x % b == 0 && x / b == (1 << i))
                {
                    // cout << x << " " << b << '\n';
                    ans = ans + cnt[x] * cnt[b];
                }
            }
        }
        // cout << ans << "||";
        // ans /= 2;
        cout << ans << '\n';
    }
}