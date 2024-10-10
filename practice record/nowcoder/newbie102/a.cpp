#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 2e5 + 10;
ll a[N];
void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    int r = 1;
    ll cur_ans = 0;
    for(int l = 1;l + k - 1 <= n;++l) {
        while(r <= l + k - 1) {
            cur_ans += a[r];
            r++;
        }   
        ans = std::max(ans, cur_ans);
        cur_ans -= a[l];
    }
    cout << ans << '\n';
}
int main() {
    solve();
}