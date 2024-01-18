#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 2e5 + 10;
double p[N];
double p_a[N],p_b[N];
void solve()
{
    ll n,a,b;
    cin >> n >> a >> b;
    double x;
    cin >> x;
    x /= 100;
    ll y;
    cin >> y;
    for(int i = 1;i <= n;++i)
    {
        cin >> p[i];
    }
    double sum = 1e18;
    
    sort(p + 1,p + 1 + n,greater<>());
    for(int i = 1;i <= n;++i)
    {
        p_a[i] = p[i] * x;
        p_b[i] = max(0.0,p[i] - y);
        p_a[i] += p_a[i - 1];
        p_b[i] += p_b[i - 1]; 
        p[i] += p[i - 1];
    }
    for(int i = 1;i <= n;++i)
    {
        double cur_sum = 0;
        if(i - 1 > a)
            break;
        cur_sum += p_a[i - 1];
        ll r = min(n,i + b - 1);
        ll res_a = a - i + 1;
        cur_sum += p_b[r] - p_b[i - 1];
        ll rr = min(r + res_a,n);
        cur_sum += p_a[rr] - p_a[r];
        cur_sum += p[n] - p[rr];
        sum = min(sum,cur_sum);
//         cout << cur_sum << " ";
    }
    if(a >= n)
    {
        sum = min(sum,p_a[n]);
    }
    cout << fixed << setprecision(12) << sum << '\n';

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