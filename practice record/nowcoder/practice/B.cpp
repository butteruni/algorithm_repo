#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r,k;
        cin >> l >> r >> k;
        ll ans = 0;
        ans = (((r + 1) / 2) - (l / 2)) % 2;
        if(k == 0)
        {
            ans = (r - l + 1) % 2;
        }
        cout << ans << '\n';
    }
}