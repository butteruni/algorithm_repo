#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>dis;
const int N = 2e5 + 10;
int idx = 0;
ll final[N];
map<ll,ll>vis;
int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);    
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vis.clear();
        idx = 0;
        vector<ll>a(n + 1);
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            ll x = a[i];

            while(x)
            {
                if(vis.count(x))
                    break;
                vis[x] = 1;
                idx++;
                final[idx] = x;
                x /= 2;
            }
        }
        ll ans = 1e18;
        for(int i = 1;i <= idx;++i)
        {
            ll ed = final[i];
            vis[ed] = 1;
            vector<ll>cost;
            for(int j = 1;j <= n;++j)
            {
                ll st = a[j];
                if(st <= ed)
                {
                    cost.push_back(ed - st);
                }else 
                {
                    ll cur_cost = 1e18;
                    for(ll k = 0;k <= 31;++k)
                    {
                        st = a[j] >> k;
                        cur_cost = min(abs(st - ed) + k,cur_cost);
                        if(st == 0)
                            break;
                    }   
                    cost.push_back(cur_cost);
                }

            }
            sort(cost.begin(),cost.end());
            ll cur_ans = 0;
            for(int j = 0;j < n - m;++j)
                cur_ans += cost[j];
            ans = min(ans,cur_ans);
        }
        std::cout << ans << '\n';
    }
}