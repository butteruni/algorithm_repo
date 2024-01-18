#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e3 + 10;
int a[N][N];
void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            char x;
            cin >> x;
            if(x == 'b')
                a[i][j]++;
        }
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1];
            a[i][j] -= a[i - 1][j - 1];
        }
    }
    for(int i = 1;i <= q;++i)
    {
        ll sum = 0;
        ll A,B,C,D;
        cin >> A >> B >> C >> D;
        A++,B++,C++,D++;
        ll dis1 = C - A;
        ll dis2 = D - B;
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