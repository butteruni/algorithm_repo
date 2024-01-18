#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e5 + 10;
int a[110],b[110];
ll cnt[N];
void solve()
{
    int n,m,x;
    cin >> n >> m >> x;

    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= m;++i)
        cin >> b[i];
    sort(a + 1,a + 1 + n,greater());
    sort(b + 1,b + 1 + m,greater());
    int l = 1,r = 1;
    int cnt = 0;
    while(x > 0)
    {
        if(a[l] == 1)
            l = n + 1;
        if(b[r] == 0)
            break;
        if(x > b[r])
        {
            if(a[l] > 1)
            {
                x -= a[l] * b[r];
                cnt+=2;
                l++,r++;
            }else 
            {
                x -= b[r];
                r++;
                cnt++;
            }
        }else 
        {
            x -= b[r];
            cnt++;
            r++;
        }
    }
    if(x > 0)
    {
        cout << -1 << '\n';
    }else 
    {
        cout << cnt << '\n';
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