#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e4 + 10;
ll ttk[N][10];
ll value[N][10];
ll dp[N][10];
ll money[N][10];
void solve()
{
    int n;
    cin >> n;
    int sum = 22;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= 5;++j)
        {   
            cin >> ttk[i][j];
        }
        for(int j = 1;j <= 5;++j)
        {   
            cin >> value[i][j];
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}