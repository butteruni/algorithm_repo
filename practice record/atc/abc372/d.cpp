#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<pair<ll,ll>>edge[n + 1];
    vector<ll>value(n + 1);
    vector<int>d(n + 1);
    for(int i = 0;i < m; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,-c});
        d[a]++;
        d[b]++;
    }
    int root = 0;

    function<void(int, int)> dfs = [&](int cur, int fa) {
        for(auto &[to, w] : edge[cur]) {
            if(to == fa) continue;
            if(value[to] == 0 && to != root) {
                value[to] = value[cur] + w;
                dfs(to, cur);
            }
        }
    };
    for(int i = 1;i <= n;++i) {
        if(d[i] != 0 && value[i] == 0) {
            root = i;
            dfs(root, -1);
        }
    }
    for(int i = 1;i <= n;++i) {
        cout << value[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}