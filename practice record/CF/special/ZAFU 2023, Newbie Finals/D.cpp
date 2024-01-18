#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 2e5 + 10;
ll dp[N][2];
ll a[N];
int n,k;
map<int,int>mp1;
map<int,int>mp2;

void solve()
{
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 0;i <= n + 10;++i)
    {
        mp1[i] = 0;
        mp2[i] = 1;
    }
    for(int i = 1;i <= k;++i)
    {
        mp1[a[i]] ++;
        mp2.erase(a[i]);
    }
    int mx = -1;
    for(int i = k;i <= n;++i)
    {
        if(i != k)
        {
            mp1[a[i - k]]--;
            if(mp1[a[i - k]] == 0)
            {
                mp2[a[i - k]] = 1;
            }
            mp1[a[i]]++;
            mp2.erase(a[i]);

        }
        for(auto [x,val]:mp2)
        {
            mx = max(mx,x);
            break;
        }
        // cout << mx << " " << i << "\n";
    }
    cout << mx << '\n';
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