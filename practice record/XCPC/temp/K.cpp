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
        ll n,k;
        cin >> n >> k;
        vector<ll>w(n);
        ll sum = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> w[i];
            sum += w[i];
        }
        ll fin = sum + k;
        for(int i = 0;i < n;++i)
        {
            cout << fixed << setprecision(10) << 1.0 * fin / sum * w[i] << ' ';
        }
        cout << '\n';
    }
}