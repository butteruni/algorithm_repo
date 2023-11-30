#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<ll,ll>mp;
const int N = 1e6 + 10;
ll sum[N];
ll l[N],r[N];
int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        cnt = 0;
        mp.clear();
        vector<PLL>seg(n);
        for(int i = 0;i < n;++i)
        {
            cin >> seg[i].first >> seg[i].second;
            mp[seg[i].first] = 0;
            mp[seg[i].second] = 0;
            mp[seg[i].first + 1] = 0;
            mp[seg[i].second + 1] = 0;
            mp[seg[i].first - 1] = 0;
            mp[seg[i].second - 1] = 0;
        }
        mp[0] = 0;
        mp[1] = 0,mp[m] = 0;
        mp[m + 1] = 0;
        for(auto &[x,val]:mp)
        {
            cnt++;
            val = cnt;
        }
        for(int i = 0;i <= cnt + 10;++i)
        {
            sum[i] = l[i] = r[i] = 0;
        }
        for(int i = 0;i < n;++i)
        {
            sum[mp[seg[i].first]]++;
            sum[mp[seg[i].second] + 1]--;
            if(seg[i].first == 1)
            {
                l[mp[1]] ++;
                l[mp[seg[i].second + 1]]--;
            }
            if(seg[i].second == m)
            {
                r[mp[m]]++;
                r[mp[seg[i].first - 1]]--;
            }
        }
        for(int i = 1;i <= cnt;++i)
        {
            sum[i] += sum[i - 1];
            l[i] += l[i - 1];
        }
        for(int i = cnt - 1;i >= 1;i--)
        {
            r[i] += r[i + 1];
        }
        ll ans = 0;
        for(int i = 1;i <= cnt;++i)
        {
            ans = max(ans,sum[i] - min(l[i],r[i]));
        }
        cout << ans << '\n';
    }
}