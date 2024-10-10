#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int cnt = 0;
    string s;
    for(int i = 1;i <= 12; ++i) {
        cin >> s;
        if(s.size() == i) 
            cnt++;
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}