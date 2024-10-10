#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ask(deque<char>s, int &val) {
    cout << "? ";
    for(auto x: s)
        cout << x;
    cout << endl;
    cin >> val;
}
void answer(deque<char>s) {
    cout << "! ";
    for(auto x:s) 
        cout << x;
    cout << endl;
}
void solve() {
    int n;
    cin >> n ;
    deque<char>s;
    int flag = 0;
    
    int insert_dir = 0;

    int insert_val = 0;


    // cout << same_0 << " " << same_1 << "\n";
    while(s.size() < n) {
        // cout << "start\n";
        if(insert_dir == 0) {
            if(insert_val == 0) {
                s.push_back('0');
            }else {
                s.push_back('1');
            }
        }else {
            if(insert_val == 0) {
                s.push_front('0');
            }else {
                s.push_front('1');
            }
        }
        ask(s, flag);
        assert(flag != -1);
        if(flag) {
            continue;
        }
        if(!insert_dir)
            s.pop_back();
        else 
            s.pop_front();
        insert_val ^= 1;
        if(insert_dir == 0) {
            if(insert_val == 0) {
                s.push_back('0');
            }else {
                s.push_back('1');
            }
        }else {
            if(insert_val == 0) {
                s.push_front('0');
            }else {
                s.push_front('1');
            }
        }
        ask(s, flag);
        assert(flag != -1);
        // cout << flag << "||\n";
        if(flag) {
            continue;
        }
        if(!insert_dir)
            s.pop_back();
        else 
            s.pop_front();
        insert_dir ^= 1;
        insert_val = 1;
    }
    answer(s);
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