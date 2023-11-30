#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
bool higher[N];
ll n,k,q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(higher,0,sizeof(higher));
        cin >> n >> k >> q;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] <= q)
                higher[i] = 1;
        }
        ll ans = 0;
        for(int i = 1;i <= n;++i)
        {
            int cur = i;
            if(higher[cur])
            {
                int cnt = 0;
                while(higher[cur])
                {
                    cnt++;
                    cur++;
                }
                if(cnt >= k)
                {
                    ll mins = cnt - k + 1;
                    ans += (mins + 1) * mins / 2;
                }
            }
            i = cur;
        }
        cout << ans << '\n';
    }
}