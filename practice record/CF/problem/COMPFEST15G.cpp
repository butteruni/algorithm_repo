#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
const int N = 2e5 + 10;
ll a[N],d[N];
// ll sum[N];
vector<PLL>ran[N];
ll n;
bool check(ll val)
{
    priority_queue<PLL,vector<PLL>,greater<PLL>>pq;
    for(int i = 1;i <= n;++i)
    {
        for(auto [r,x]:ran[i])
        {
            if(x > 0)
                pq.emplace(r,x);
        }
        ll tmp = val;
        while(tmp > 0 && !pq.empty())
        {
            auto [l, x] = pq.top();
            if(l < i)
                return 0;
            pq.pop();
            ll m = min(x,tmp);
            tmp -= m;
            x -= m;
            if(x > 0)
                pq.emplace(l,x);
        }
    }
    if(pq.size())
    {
        return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(ll i = 1;i <= n;++i)
    {
        cin >> a[i];
        ran[i].clear();
    }
    for(ll i = 1;i <= n;++i)
    {
        cin >> d[i];
        int l = max(1ll,i - d[i]);
        int r = min(n,i + d[i]);
        ran[l].push_back(make_pair(r,a[i]));
    }
    ll l = 0,r = 1e9;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        // cout << mid << endl;
        if(check(mid))
        {
            r = mid;;
        }else 
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}