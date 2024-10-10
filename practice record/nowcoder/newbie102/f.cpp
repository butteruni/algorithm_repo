#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
const int mod = 998244353;
ll a[N];
ll pos_in_a[N];
ll b[N];
ll freedom_cnt[N];
ll pos_in_b[N];

map<int,int>p;
void solve() {
    int n,w;
    cin >> n >> w;
    for(int i = 1;i <= n;++i) {
        a[i] = 0,pos_in_a[i] = 0;
        b[i] = 0,pos_in_b[i] = 0;
    }
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
        if(a[i] != -1) {
            pos_in_a[a[i]] = i;
        }
        freedom_cnt[i] = freedom_cnt[i - 1] + (a[i] == -1);
    }
    ll ans = 1;
    ll cnt = 0;
    for(int i = 1;i <= n;++i) {
        cin >> b[i];
        pos_in_b[b[i]] = i;
        int pos_r = std::min(n, i + w);
        if(pos_in_a[b[i]] == 0) {
            ans = ans * (freedom_cnt[pos_r] - cnt) % mod;
            cnt++;
        } else if(pos_in_a[b[i]] > pos_r) 
            ans = 0;
    }
    cout << ans << '\n';

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}