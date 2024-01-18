#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<ll,ll>mp;
ll sum = 0;
void solve()
{
    mp.clear();
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        ll op,x;
        cin >> op >> x;
        if(op == 1)
        {
            mp[x]++;
            sum += (1ll << x);
        }
        
        if(op == 2)
        {
            bool ok = 1;
            int st = 0;
            ll cur = 0;
            for(ll j = 0;j <= 30;++j)
            {
                cur += mp[j] * (1ll << j);
                if((x >> j) & 1)
                {   
                    cur -= (1ll << j);
                }
                if(cur < 0)
                    ok = 0;

            }
            if(ok)
            {
                cout << "YES\n";
            }else 
            {
                cout << "NO\n";
            }
            
        }

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}