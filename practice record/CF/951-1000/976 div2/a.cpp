#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qpow(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    int cnt = 0;
    if(k == 1) {
        cout << n << '\n';
        return;
    }
    while(n) {
        cnt += n % k;
        n /= k;
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}