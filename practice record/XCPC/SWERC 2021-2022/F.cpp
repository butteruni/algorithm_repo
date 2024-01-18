#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll p[N];
ll mins_p[N];
ll add[N];
ll del[N];
void solve()
{
    ll n,a,b;
    cin >> n >> a >> b;
    // i - j <= min (p_i,p_j)
    // and
    // j - i <= min(p_i,p_j)
    
    // i - j <= p_i && i - j <= p_j && j - i <= p_i && j - i <= p_j


    // -j <= p_i - i && i <= p_j + j && j <= p_i + i && -i <= p_j - j
    for(int i = 1;i <= n;++i)
    {
        cin >> p[i];
        mins_p[i] = -1 * p[i];
        add[i] = p[i] + i;
        del[i] = p[i] - i;
    }
    if(a == b)
    {
        cout << 0 << '\n';
        return;
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