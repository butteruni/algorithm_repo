#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    string s;
    cin >> s;
    map<char, int>pos;
    for(int i = 0;i < s.size(); ++i) {
        pos[s[i]] = i;
    }
    int ans = 0;
    for(int i = 1;i < 26; ++i) {
        char x = 'A' + i;
        ans += abs(pos[x] - pos[x - 1]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}