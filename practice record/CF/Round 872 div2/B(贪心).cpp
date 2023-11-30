#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,m;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int idx = 1;
        while(idx <= n * m)
        {
            cin >> a[idx];
            idx++;
        }
        // cout << '\n';
        sort(a + 1,a + 1 + n * m);
        // cout << a[1] << "  " << a[n * m] << '\n';
        ll ans1 = 0;
        ans1 += (a[n * m] - a[1]) * (max(n,m) - 1) + (a[n * m] - a[2]) * (min(n,m) - 1);
        ans1 += (a[n * m] - a[1]) * (n - 1) * (m - 1);
        ll ans2 = 0;
        ans2 += (a[n * m] - a[1]) * (max(n,m) - 1) + (a[n * m - 1] - a[1]) * (min(n,m) - 1);
        ans2 += (a[n * m] - a[1]) * (n - 1) * (m - 1);
        cout << max(ans1,ans2) << '\n';
    }
}