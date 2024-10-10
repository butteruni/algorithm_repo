#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N), pre(2 * N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        pre[i + 1] = pre[i] + A[i];
    }
    for (int i = 0; i < N; i++) {
        pre[N + i + 1] = pre[N + i] + A[i];
    }
    
    std::vector<std::vector<int>> adj(2 * N + 1);
    std::vector<int> f(2 * N + 1);
    std::vector<int> stk;
    auto check = [&](int s) {
        adj.assign(2 * N + 1, {});
        for (int i = 0, j = 0; i < 2 * N; i++) {
            while (j < 2 * N && pre[j] - pre[i] < s) {
                j++;
            }
            f[i] = j;
            adj[j].push_back(i);
        }
        
        int ans = 0;
        auto dfs = [&](auto &self, int x) -> void {
            if (x < N) {
                if (stk.size() >= K && stk[stk.size() - K] <= x + N) {
                    ans++;
                }
            }
            stk.push_back(x);
            for (auto y : adj[x]) {
                self(self, y);
            }
            stk.pop_back();
        };
        dfs(dfs, 2 * N);
        return ans;
    };
    
    int lo = 0, hi = pre[N] / K;
    int ans = -1;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        int res = check(m);
        if (res == 0) {
            hi = m - 1;
        } else {
            lo = m;
            ans = N - res;
        }
    }
    
    std::cout << lo << " " << ans << "\n";
    
    return 0;
}