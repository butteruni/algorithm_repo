#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll res_k = k;
    vector<ll>a(n);
    for(auto &x : a) {
        cin >> x;
        res_k -= x;
    }
    vector<ll>b = a;
    // b.push_back(-1e18);
    // b.push_back(1e18);
    sort(b.begin(), b.end());
    vector<ll> pre(n);
    for(int i = 0;i < n;++i) {
        pre[i] = b[i];
        if(i > 0)
            pre[i] += pre[i - 1]; 
    }
    for(int i = 1;i < n;++i) {
        pre[i] = b[i] * (i + 1) - pre[i];
        // cout << pre[i] << " ";
    }
    // cout << '\n';
    vector<ll>ans(n);
    fill(ans.begin(),ans.end(), -1);
    auto check = [&](ll i_pos, ll vote) {
        ll mid = a[i_pos] + vote;
        ll res = res_k - vote;
        auto pos = lower_bound(b.begin(), b.end(), mid);
        cout << res << '\n';
        int rank = pos - b.begin();
        if(rank > 0)
            rank --;
        int lpos = 0, rpos = rank;
        while(lpos < rpos) {
            ll midpos = (lpos + rpos + 1) >> 1;
            cout << pre[rank] - pre[rank - midpos] + midpos * (mid - b[rank])<< " " << lpos <<" " << rpos << '\n';
            if(pre[rank] - pre[rank - midpos] + midpos * (mid - b[rank]) < res + val) {
                lpos = midpos;
            }else {
                rpos = midpos - 1;
            }
            
        }
        cout << a[pos] << " " << lpos << " " << vote << " " << rank << '\n';
        return (rank + 1 - lpos + m) > n; 
    };
    for(int i = 0;i < n;++i) {
        ll l = 0, r = res_k;
        bool flag = 0;
        while(l < r) {
            ll mid = (l + r) >> 1;
            if(check(i, mid)) {
                r = mid;
                flag = 1;
            }else {
                l = mid + 1;
            }
        }
        if(check(i, l)) {
            flag = 1;
        }
        if(flag) {
            ans[i] = l;
        }
    }
    for(auto x : ans) {
        cout << x << " ";
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