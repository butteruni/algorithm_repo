#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], freq[N], n;

int run(int mx) {
    int res = mx;
    long long dp[mx + 1] = {};
    for (int i = mx; i >= 1; --i) {
        int cnt = 0;
        for (int j = i; j <= mx; j += i) {
            cnt += freq[j];
        }
        dp[i] = 1ll * cnt * (cnt - 1) / 2;
        for (int j = i + i; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
        if (dp[i] > 0)
            res = i;
    }
    return res;
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mx = a[n - 1];
    for (int i = 0; i <= mx; ++i) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }
    int small = 1e9, var = n - 2;
    long long ans = a[0];
    for (int i = 1; i < n; i++) {
        small = min(small, __gcd(a[0], a[i]));
    }
    if (n != 1)
        ans += small;
    while (var > 0) {
        freq[small]++;
        int ret = run(mx);
        if (ret == small) {
            ans += 1ll * var * small;
            break;
        }
        ans += ret;
        small = ret;
        var--;
    }
    cout << ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        if (t)
            cout << "\n";
    }

    return 0;
}