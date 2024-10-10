#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> coins;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        coins.emplace_back(r, c);
    }
    sort(coins.begin(), coins.end());
    vector<int> dp(n, 1e9), id(n, -1), pre(n);
    for (int i = 0; i < n; i++) {
        int it = upper_bound(dp.begin(), dp.end(), coins[i].second) - dp.begin();
        dp[it] = coins[i].second;
        id[it] = i;
        pre[i] = (it ? id[it - 1] : -1);
    }
    int m = n - 1;
    while (id[m] == -1) --m;
    vector<pair<int, int>> path = {{h, w}};
    int now = id[m];
    while (now != -1) {
        path.push_back(coins[now]);
        now = pre[now];
    }
    path.emplace_back(1, 1);
    reverse(path.begin(), path.end());
    string s;
    for (int i = 0; i < (int) path.size() - 1; i++) {
        int d = path[i + 1].first - path[i].first;
        int r = path[i + 1].second - path[i].second;
        while (d--) s.push_back('D');
        while (r--) s.push_back('R');
    }
    cout << m + 1 << '\n' << s << '\n';
}

