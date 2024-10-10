#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll val) {
    return val - (ll)std::sqrt(val);
}
bool is_square(ll val) {
    ll tmp = (ll)std::sqrt(val);
    return tmp * tmp == val;
}
void solve() {
    ll k;
    cin >> k;

    ll l = 1, r = 2e18;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (calc(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(is_square(l))
        l--;
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
