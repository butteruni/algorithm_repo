#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qpow(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve() {
    for(int a = 0;a <= 16;++a) {
        for(int b = 0;b <= 16;++b) {
            for(int c = 0;c <= 16;++c) {
                for(int d = 0;d <= 16;++d) {
                    if((a | b) - (a & c) == d) {
                        for(int i = 3;i >= 0;--i) {
                            cout << ((a >> i) & 1);
                        }
                        cout << '\n';
                        for(int i = 3;i >= 0;--i) {
                            cout << ((b >> i) & 1);
                        }   
                        cout << '\n';
                        for(int i = 3;i >= 0;--i) {
                            cout << ((c >> i) & 1);
                        }
                        cout << '\n';
                        for(int i = 3;i >= 0;--i) {
                            cout << ((d >> i) & 1);
                        }
                        cout << '\n';
                        cout << "==========\n";
                        
                    }
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}