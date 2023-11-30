#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
multiset<int> lmax, rmin;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == '+') 
        {
            lmax.insert(l);
            rmin.insert(r);
        }
        else 
        {
            lmax.erase(lmax.find(l));
            rmin.erase(rmin.find(r));
        }
        if (lmax.size() <= 1 || *(--lmax.end()) <= *(rmin.begin())) cout << "NO\n";
        else cout << "YES\n";
    }
}