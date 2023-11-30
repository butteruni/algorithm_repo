#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll n, m;
ll cnt;
int row[N], col[N];
int k[N];
void solve()
{
    cin >> n >> m;
    ll t1 = n * (n + 1) / 2;
    ll t2 = m * (m + 1) / 2;
    cnt = t1 * t2;
    if (cnt % 2 == 1)
    {
        cout << "No\n";
    }
    else
    {
        cnt >>= 1;
        cnt -= n * m;
        if (cnt % n == 0) // 横着一样
        {
            ll sum = cnt / n;
            int sz=0;
            ll tot = 0;
            while (sum)
            {
                if(tot>m)
                {
                    break;
                }
                ll l = 2, r = m;
                while (l < r)
                {
                    ll mid = l + r + 1 >> 1;
                    if (l * (l - 1) / 2 > sum)
                        r=mid-1;
                    else
                        l=mid+1;
                }
                sum -= l * (l - 1) / 2;
                tot += l;
                k[++sz]=l;
            }
            if (tot <= m)
            {
                cout<<"Yes\n";
                int idx = 1;
                for (int i = 1; i <= sz; i++)
                {
                    int u = i % 2;
                    for (int j = 1; j <= k[i]; j++)
                    {
                        row[idx] = u;
                        idx++;
                    }
                }
                for (; idx <= m; idx++)
                {
                    row[idx] = row[idx - 1] ^ 1;
                }
                for(int i=1;i<=n;i++)
                {
                    int u=i%2;
                    for(int j=1;j<=m;j++)
                    {
                        cout<<(row[j]^u)<<" \n"[j==m];
                    }
                }
                return;
            }
        }
        if (cnt % m == 0)
        {
            ll sum = cnt / m;
            int sz=0;
            ll tot = 0;
            while (sum)
            {
                if(tot>n)
                {
                    break;
                }
                ll l = 2, r = n;
                while (l < r)
                {
                    ll mid = l + r +1 >> 1;
                    if (l * (l - 1) / 2 > sum)
                        r=mid-1;
                    else
                        l = mid;
                }
                sum -= l * (l - 1) / 2;
                tot += l;
                k[++sz]=l;
            }
            if (tot <= n)
            {
                cout<<"Yes\n";
                int idx = 1;
                for (int i = 1; i <= sz; i++)
                {
                    int u = i % 2;
                    for (int j = 1; j <= k[i]; j++)
                    {
                        col[idx] = u;
                        idx++;
                    }
                }
                for (; idx <= n; idx++)
                {
                    col[idx] = col[idx - 1] ^ 1;
                }
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        int u=j%2;
                        cout<<(col[i]^u)<<" \n"[j==m];
                    }
                }
                return;
            }
        }
        cout<<"No\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}