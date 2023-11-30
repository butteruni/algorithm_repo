#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>w(n),x(n);
    for(int i = 0;i < n;++i)
        cin >> w[i] >> x[i];
    ll ans = 0;
    for(int i = 0;i <= 23;++i)
    {
        ll cur_ans = 0;
        for(int j = 0;j < n;++j)
        {
            ll time = (i + x[j]) % 24;
            if(time >= 9 && time < 18)
            {
                cur_ans += w[j];
            }
        }
        ans = max(ans,cur_ans);
    }
    cout << ans << '\n';
}