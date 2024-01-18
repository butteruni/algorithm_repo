#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
PLL pos[N];
int n;
bool check(ll val)
{
    ll l = 0,r = 0;
    int cnt = 0;
    for(int i = 1;i <= n;++i)
    {
        bool ok = 0;
        if(abs(pos[i].first - l) <= val 
        || abs(pos[i].first - r) <= val 
        || abs(pos[i].second - l) <= val 
        || abs(pos[i].second - r) <= val) // 不相交
        {
            ok = 1;

        }
        if( l <= pos[i].first && pos[i].first <= r) // 已经相交
            ok = 1;
        if(l <= pos[i].second && pos[i].second <= r)
            ok = 1;
        if(pos[i].first <= l && r <= pos[i].second)
            ok = 1;
        if(ok)
        {
            l = max(pos[i].first,l - val);
            r = min(r + val,pos[i].second);
            cnt++;
        }else 
        {
            break;
        }
        
    }
    return cnt == n;
}
void solve()
{
    cin >> n;

    for(int i = 1;i <= n;++i)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    ll l = 0,r = 1e18;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        if(!check(mid))
        {
            l = mid + 1;
        }else 
        {
            r = mid;
        }
    }
    cout << l << '\n';

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