#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n,k;
    cin >> n >> k;
    k %= 4;
    int cnt = 0;
    if(k == 0 && n != 0)
    {
        cout << -1 << '\n';
        return ;
    }
    if(n == 0)
    {
        cout << 0 << '\n';
        return ;
    }
    int need = 4 - n;
    if((need & 1) && k % 2 == 0)
    {
        cout << -1 << '\n';
        return;
    }
    while(n != 0)
    {
        n += k;
        n %= k;
        cnt++;
    }
    cout << cnt << '\n';
    
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