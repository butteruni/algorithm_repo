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
    ll b,c,d;
    cin >> b >> c >> d;
    ll ans = 0;
    bool flag = 0;
    for(ll i = 0;i <= 60;++i) {
        if((d >> i) & 1) {
            if((b >> i) & 1) {
                if((c >> i) & 1) {
                    continue;
                }else{
                    continue;
                }
            }else {
                if((c >> i) & 1) {
                    flag = 1;
                }else {
                    ans |= (1LL << i);
                }
            }
        }else {
            if((b >> i) & 1) {
                if((c >> i) & 1) {
                    ans |= (1LL << i);
                }else{
                    // ans |= (1LL << i);
                    flag = 1;
                }
            }else {
                if((c >> i) & 1) {
                    // flag = 1;
                    // ans |= (1LL << i);
                    continue;
                }else {
                    continue;
                }
            }
        }
    }


    if(flag) {
        cout << -1 << '\n';
    }else {
        // assert(((ans | b) - (ans & c)) == d);
        cout << ans << '\n';
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