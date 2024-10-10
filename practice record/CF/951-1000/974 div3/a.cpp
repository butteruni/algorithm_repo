#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    ll s = 0;
    int cnt = 0;
    for(auto x: a) {
        if(x >= k)
            s += x;
        else if(x == 0)
            if(s) {
                s--;
                cnt++;
            }
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}