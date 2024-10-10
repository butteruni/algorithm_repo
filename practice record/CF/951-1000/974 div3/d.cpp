#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    int l, r;
};
bool cmp1(node a, node b) { return a.l < b.l; }
bool cmp2(node a, node b) { return a.r < b.r; }
void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> cnt(n + 10);
    vector<int> start_at(n + 10);
    vector<int> end_at(n + 10);
    vector<node> job1;
    vector<node> job2;
    for (int i = 1; i <= k; ++i) {
        int l, r;
        cin >> l >> r;
        node job;
        job.l = l, job.r = r;
        job1.push_back(job);
        job2.push_back(job);
    }
    sort(job1.begin(), job1.end(), cmp1);
    sort(job2.begin(), job2.end(), cmp2);

    // cout << endl;
    int pos1 = 0, pos2 = 0;
    for (int i = 1; i <= n; ++i) {
        while (job1[pos1].l == i && pos1 < k) {
            start_at[i]++;
            pos1++;
        }
        while (job2[pos2].r == i && pos2 < k) {
            end_at[i]++;
            pos2++;
        }
    }
    int r = 1;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        while (r <= i + d - 1 && r <= n) {
            cur += start_at[r];
            r++;
        }
        cnt[i] = cur;
        assert(cnt[i] >= 0);
        cur -= end_at[i];
    }
    // for(int i = 1;i <= n;++i)
    //     cout << cnt[i] << " ";
    // cout << '\n';
    int st_1 = 0, cnt_1 = -1e8;
    int st_2 = 0, cnt_2 = 1e8;
    for (int i = 1; i + d - 1 <= n; ++i) {
        if (cnt[i] > cnt_1) {
            cnt_1 = cnt[i];
            st_1 = i;
        }
        if (cnt[i] < cnt_2) {
            cnt_2 = cnt[i];
            st_2 = i;
        }
    }
    cout << st_1 << " " << st_2 << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}