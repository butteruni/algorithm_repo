#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5050;
ll a[N];
ll b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m,u;
    cin >> n >> m >> u;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
        cin >> b[i];
    int mx = 0;
    for(int l = 1;l <= n;++l)
    {
        bool ok = 1;
        ll res = m;
        ll sum = 0;
        for(int r = l;r <= n;++r)
        {
            res -= a[r];
            sum += b[r];
            if(res < 0 || sum > u)
            {
                ok = 0;
                break;
            }
            mx = max(mx,r - l + 1);
        }
    }
    cout << mx << '\n';
}