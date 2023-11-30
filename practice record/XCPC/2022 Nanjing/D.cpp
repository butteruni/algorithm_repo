#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
ll n,k,m,c,d;
int tag[N];
bool check(ll val)
{
    vector<int>change[n + 2];
    int sum = 0;
    for(int i = 0;i <= n + 1;++i)
    {
        tag[i] = 0;
        change[i].clear();
    }
    for(int i = 1;i <= n;++i)
    {
        if(a[i] >= val)
        {
            sum++;
            tag[i] = 1;
        }else 
        {
            ll l = 0,r = min(m,(ll)i);
            if(a[i] + c + (min(r,(ll)i) - 1) * d < val)
                continue;
            if(a[i] + c >= val)
            {
                // int l = 0;
                int r_limit = min(n + 1,i + m);
                change[r_limit].push_back(i);
                continue;
            }
            while(l < r)
            {
                ll mid = (l + r + 1) >> 1;
                if(a[i] + c + (mid - 1) * d < val)
                {
                    l = mid;
                }else 
                {
                    r = mid - 1;
                }
            }
            int r_limit = min(n + 1,max(i - l + m,m + 1));

            assert(r_limit < n + 2);
            change[r_limit].push_back(i);
        }
    }
    // cout << sum << " ";
    if(sum >= k)
        return 1;
    for(ll i = 1;i <= m;++i)
    {
        if(a[i] + (i - 1) * d + c >= val)
        {
            sum += 1 - tag[i];
            tag[i] = 1;
        }
    }
    // cout << sum << " ";
    
    if(sum >= k)
        return 1;
    for(int i = m + 1;i <= n;++i)
    {
        ll sz = change[i].size();
        // cout << sz << " ";
        sum -= sz;
        // cout << sum <<" ";
        if(a[i] + (m - 1) * d + c >= val)
        {
            sum += 1 - tag[i];
            tag[i] = 1;
        }
        // cout << sum << "\n";
        if(sum >= k)
            return 1;
    }
    return 0;
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k >> m >> c >> d;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    ll l = 0,r = 1e18;
    while(l < r)
    {
        ll mid = (r + l + 1) >> 1;
        // cout << mid << '\n';
        if(check(mid))
            l = mid;
        else 
            r = mid - 1;
        // cout << " ";
    }

    cout << l << '\n';
}