#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<int,int>mp;
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
        mp[i] = 1;
    for(int i = 1;i < n;++i)
    {
        int x;
        cin >> x;
        mp.erase(x);
    }
    for(auto [x,val]:mp)
    {
        cout << x << '\n';
        return ;
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