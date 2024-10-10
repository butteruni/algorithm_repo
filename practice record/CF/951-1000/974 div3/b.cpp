#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    if(k % 4 == 0) {
        cout << "YES\n";
        return;
    }
    if(k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    if(k % 4 == 1) {
        if(n & 1) {
            cout << "NO\n";
        }else 
            cout << "YES\n";
    }else if(k % 4 == 3) {
        if(n & 1) {
            cout << "YES\n";
        }else 
            cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}