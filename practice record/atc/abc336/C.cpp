#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n;
    cin >> n;
    n--;
    vector<ll>ans;
    if(n == 0)
    {
        cout << 0 << "\n";
        return;
    }

    while(n)
    {
        ll res = n % 5ll;
        ans.push_back(res * 2);
        n /= 5;
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout << x;
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