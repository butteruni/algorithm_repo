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
        vector<ll>l(n + 1);
        for(int i = 1;i <= n;++i)
        {
            cin >> l[i];
        }
        vector<ll>r(n + 1);
        for(int i = 1;i <= n;++i)
        {
            cin >> r[i];
        }
        l[0] = r[0] = 0;
        ll ans = 1e10;
        ll step = 0,cnt = 0,cnt_1 = 0,len = 0;
        for(int i = 1;i <= n;++i)
        {
            ll cur_sz = r[i] - l[i] + 1;
            if(cur_sz > 1)
            {
                len += cur_sz;
            }else 
            {
                cnt_1++;
            }
            if(len < k)
            {
                if(len + cnt_1 >= k)
                {
                    ll cur_ans = (i - cnt_1 + k - len);
                    // cout << cur_ans << " ";
                    ans = min(ans,cur_ans * 2 + r[i]);
                }
            }else 
            {
                ans = min(ans,r[i] - (len - k) + 2 * (i - cnt_1));
            }
        }
        if(ans == 1e10)
        {
            cout << -1 << '\n';
        }else 
        {
            cout << ans << '\n';
        }
    }
}