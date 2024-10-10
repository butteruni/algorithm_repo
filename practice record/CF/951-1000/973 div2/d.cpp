#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    int val, pos;
    bool operator<(const node &b) const{
        return this->val == this->val ? 
        this->val > b.val : this->pos > b.pos;
    }
    bool operator>(const node &b) const{
        return this->val == this->val ? 
        this->val < b.val : this->pos < b.pos;
    }
};



void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    priority_queue<node> lessqueue;
    priority_queue<node, vector<node>, greater<node> > greaterqueue;  
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        node tmp;
        tmp.val = a[i];
        tmp.pos = i;
        lessqueue.push(tmp);
        greaterqueue.push(tmp);

    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}