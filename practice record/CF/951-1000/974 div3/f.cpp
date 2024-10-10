#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
vector<ll> edges[N];
ll val[N];
ll dp[N][2];
ll d[N];
ll n, c;
void dfs(int root, int fa) {
    ll pre_sum1 = 0;
    ll pre_sum0 = 0;
    vector<pair<ll,ll>>son_val;
    // cout << root << " ";
    for(auto son : edges[root]) {
        if(son != fa) {
            dfs(son, root);
            pre_sum1 += max(dp[son][0], dp[son][1] - 2 * c);
            pre_sum0 += max(dp[son][0], dp[son][1]);
            son_val.push_back({dp[son][1], son});
        }
    }
    sort(son_val.begin(),son_val.end(),[](pair<ll,ll>a, pair<ll,ll>b) {
        return a.first < b.first;
    });
    // if(!cnt_son) {
    //     dp[root][0] = 0;
    //     dp[root][1] = val[root];
    // }else {
    dp[root][0] = pre_sum0; // 所有儿子都取最大，自身被消耗无影响
    dp[root][1] = val[root] + pre_sum1;

}
void solve() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        dp[i][0] = 0, dp[i][1] = 0;
        d[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        d[u]++, d[v]++;
    }
    int root = 1;
    for(int i = 1;i <= n;++i) {
        if(d[i] == 1) {
            root = i;
            break;
        }
    }
    
    dfs(root, 0);
    // cout << '\n';
    // for(int i = 1;i <= n;++i) {
    //     cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
    // }
    cout << max(dp[root][0], dp[root][1]) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
