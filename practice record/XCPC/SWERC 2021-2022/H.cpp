#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<ll,ll>factor_w;
map<ll,ll>factor_m;
map<ll,ll>factor_ww;
map<ll,ll>factor_mm;
map<ll,ll>factor_www;
map<ll,ll>factor_mmm;
map<ll,ll>ans;
void solve()
{
    ll w,m;
    cin >> w >> m;
    // vector<int>ans;
    factor_m.clear();
    factor_w.clear();
    factor_mm.clear();
    factor_ww.clear();
    factor_mmm.clear();
    factor_www.clear();
    ans.clear();
    for(ll i = 1;i * i <= w;++i)
    {
        if(w % i == 0)
        {
            factor_w[i] = 1;
            factor_w[w / i] = 1;
        }
    }
    for(ll i = 1;i * i <= m;++i)
    {
        if(m % i == 0)
        {
            factor_m[i] = 1;
            factor_m[m / i] = 1;
        }
    }
    w -= 1;
    m -= 1;
    for(ll i = 1;i * i <= w;++i)
    {
        if(w % i == 0)
        {
            factor_ww[i] = 1;
            factor_ww[w / i] = 1;
        }
    }
    for(ll i = 1;i * i <= m;++i)
    {
        if(m % i == 0)
        {
            factor_mm[i] = 1;
            factor_mm[m / i] = 1;
        }
    }
    w -= 1;
    m -= 1;
    for(ll i = 1;i * i <= w;++i)
    {
        if(w % i == 0)
        {
            factor_www[i] = 1;
            factor_www[w / i] = 1;
        }
    }
    for(ll i = 1;i * i <= m;++i)
    {
        if(m % i == 0)
        {
            factor_mmm[i] = 1;
            factor_mmm[m / i] = 1;
        }
    }
    for(auto [x,val] : factor_w) 
    {
        if(factor_mmm.count(x))
        {
            ans[x] = 1;
        }
    }
    for(auto [x,val] : factor_m)
    {
        if(factor_www.count(x))
        {
            ans[x] = 1;
        }
    }
    for(auto [x,val] : factor_mm)
    {
        if(factor_ww.count(x))
        {
            ans[x] = 1;
        }
    }
    for(auto [x,val] : factor_w) 
    {
        if(factor_mm.count(x) && factor_www.count(x))
        {
            ans[x] = 1;
        }
    }
    for(auto [x,val] : factor_m) 
    {
        if(factor_mmm.count(x) && factor_ww.count(x))
        {
            ans[x] = 1;
        }
    }
    cout << ans.size() << ' ';
    for(auto [x,val] : ans)
    {
        cout << x << " ";
    }
    cout << '\n';
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