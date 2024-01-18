#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll N,P,L,T;
    cin >> N >> P >> L >> T;
    ll add1 = L + 2 * T;
    ll add2 = L + 1 * T;
    ll add3 = L + 0 * T;
    ll mx_task = (N + 6) / 7;
    ll cnt_1 = mx_task / 2;
    if(cnt_1 * add1 >= P)
    {
        ll need = (P + add1 - 1) / add1;
        cout << N - need << '\n';
        return;
    }
    N -= cnt_1;
    P -= cnt_1 * add1;
    if(mx_task & 1)
    {
        P -= add2;
        N--;
    }
    if(P <= 0)
    {
        cout << N << '\n';
        return ;
    }
    N -= (P + add3 - 1) / add3;
    cout << N << '\n';


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