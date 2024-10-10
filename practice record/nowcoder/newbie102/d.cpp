#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
ll a[N];
ll pre[N];
ll tmp[N][N];
map<int,int>ans;
void solve() {
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for(int l = 1;l <= n;++l) {
        ll sum = 0;
        for(int r = l;r <= n;++r) {
            sum += a[r];
            ll d = std::sqrt(sum);
            if(d * d == sum || (d + 1) * (d + 1) == sum) {
                tmp[l][r] = 1;
            } 
        }
    }
    while(q--) {
        int pos;
        cin >> pos;
        if(ans.count(pos)) {
            cout << ans[pos] << '\n';
            continue;
        }
        ll cnt = 0;
        for(int l = 1;l <= pos;++l) {
            for(int r = pos;r <= n;++r) {
                cnt += tmp[l][r];
            }
        }
        ans[pos] = cnt;
        cout << cnt << '\n';
    }
}
int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve(); 
}