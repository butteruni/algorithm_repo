#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
int cnt[N];
int a[N];
void solve()
{
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    for(int i = 1;i <= n;++i)
    {
        a[i] = s[i] - '0';
    }
    a[0] = 0;
    for(int i = 1;i <= n;++i)
    {
        cnt[i] = cnt[i - 1];
        if(a[i] == 1 && a[i - 1] == 0)
        {
            cnt[i]++;
        }
    }
    cout << cnt[n] << endl;
    for(int i = 1;i <= q;++i)
    {
        int l,r;
        cin >> l >> r;
        int ans = cnt[n];
        if(a[l] == 1 && a[l - 1] == 1)
            ans++;
        if(a[r] == 1 && a[r - 1] == 1)
            ans++;
        if(a[l - 1] == 1 && a[r] == 1)
            ans--;
        if(a[l] == 1 && a[r + 1] == 1)
            ans--;
        cout << ans << '\n';
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