#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll a[N];
map<pair<ll,ll>,ll>vis;

void solve() {
    int n;
    cin >> n;
    // n 和 n - 1 互质
    // n is even , gcd(n, n - 2) = 2
    // n is odd ,n - 1 is even
    if (n == 1) {
        cout << 0 << '\n';
        return;
    } 
    if (n == 2) {
        cout << 2 << '\n';
        return;
    } 
    if (n == 3) {
        cout << 4 << '\n';
        return;
    } 
    if (n % 2 == 0) {
        cout << 4 << '\n';
        return;
    } else if (n % 2 & 1) {
        cout << 6 << '\n';
    }
}
int main() { solve(); }