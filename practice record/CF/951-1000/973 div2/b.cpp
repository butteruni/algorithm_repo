#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n ;
    vector<ll>a(n);
    vector<ll>pre(n);
    for(int i = 0;i < n;++i) {
        cin >> a[i];
        pre[i] = a[i];
        if(i > 0)
            pre[i] += pre[i - 1];
    }    
    if(n == 1) {
        cout << a[0] << '\n';
        return;
    }else if(n == 2){
        cout << a[n - 1] - a[n - 2] << '\n';
    }else {
        cout << a[n - 1] - a[n - 2] + pre[n - 3]<< '\n';
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}