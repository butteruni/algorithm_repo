#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    map<char,int>mp;
    for(int i = 0;i < n;++i)
    {
        // int j = i;
        mp[s[i]]++;
    }
    for(auto [x,val]:mp)
    {
        if(val >= x - 'A' + 1)
            ans++;
    }
    cout << ans << '\n';
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