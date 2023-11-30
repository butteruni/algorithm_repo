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
        int n,m;
        cin >> n >> m;
        vector<ll>a(n + 1);
        a[0] = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;++i)
        {
            a[i] += a[i - 1];
        }
        ll sum = a[n];
        for(int i = 1;i <= m;++i)
        {
            ll l,r,k;
            cin >> l >> r >> k;
            ll cur_sum = k * (r - l + 1);
            if((sum - (a[r] - a[l - 1]) + cur_sum) & 1)
            {
                cout << "YES\n";
            }else 
            {
                cout << "NO\n";
            }
        }
    }
}