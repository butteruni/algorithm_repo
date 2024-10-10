#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    for(auto &x : a) {
        cin >> x;
        sum += x;
    }
    sort(a.begin(),a.end());
    ll cnt = 0;
    int pos = n - 1;
    while(a[pos] == a.back() && pos >= 0) {
        pos--;
        cnt++;
    }
    ll l = 0, r = 1e18;
    if(n <= 2) {
        cout << -1 << '\n';
        return ;
    }
    auto check = [&](ll mid) ->auto{
        ll cur_sum = sum;
        cur_sum +=  mid;
        double average = 1.0 * cur_sum / n;
        auto it = lower_bound(a.begin(),a.end(), average / 2.);
        // cout << average / 2 << " " << mid << " " << it - a.begin() << '\n';
        return (it - a.begin()) <= (n / 2);
    };
    while(l < r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}