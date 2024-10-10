#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m + 1);
    vector<ll> d(m + 1);
    vector<ll> k(m + 1);
    vector<ll> p(n + 1);
    for(int i = 1;i <= n;++i) {
        p[i] = i;
    }
    for(int i = 1;i <= m;++i) {
        cin >> a[i] >> d[i] >> k[i];
    
    }
    function<ll(ll)> find = [&](ll x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    };
    for(int i = 1;i <= m;++i) {
        
    }
    int cnt = 0;
    for(int i = 1;i <= n;++i) {
        if(p[i] == i) {
            cnt++;
        }
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