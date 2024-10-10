#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
ll a[N];
const int MAXN = 1e6 + 10;
int cnt;
bool vis[MAXN];
ll pri[MAXN];
ll st[MAXN];
void init() {
    vis[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) {
            pri[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++) {
            if (1ll * i * pri[j] >= MAXN)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
}
ll count(ll n) {
    ll sum = 1;
    for (ll i = 1; pri[i] * pri[i] <= n; i++) {
        if (n % pri[i] == 0) {
            ll tmp = 0;
            while (n % pri[i] == 0) {
                n /= pri[i];
                tmp++;
            }
            sum = sum * (tmp + 1);
        }
    }
    if (n > 1) sum = sum * 2;
    return sum;
}
map<int,int>p;
void solve() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    int mx = a[n];
    for(int i = 1;i <= n;++i) {
        if(p.count(a[i]))
            continue;
        p[a[i]]++;
        int j = a[i];
        while(j <= mx) {
            st[j]++;
            j += a[i];;
        }
    }
    ll ans = 0;
    for(int i = 1;i <= mx;++i) {
        if(st[i] == count(i))
            ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
}