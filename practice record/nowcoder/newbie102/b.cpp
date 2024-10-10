#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 2e5 + 10;
ll a[N];
void solve() {
    int n;
    deque<char>p;
    cin >> n;
    for(int i = 0;i < n; ++i) {
        char x;
        cin >> x;
        if(p.size()) {
            if(x == 'b' && p.back() == 't')
                p.pop_back();
            else if(x == 'c' && p.back() == 'f')
                p.pop_back();
            else 
                p.push_back(x);
        }else {
            p.push_back(x);
        }
    }
    cout << p.size() << '\n';
}
int main() {
    solve();
}