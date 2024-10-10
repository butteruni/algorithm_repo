#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x,y;
    cin >> n >> x >> y;
    // cout << n << " " << x << " " << y << '\n';
    cout << std::max((n + x - 1) / x, (n + y - 1) / y) << '\n';;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}