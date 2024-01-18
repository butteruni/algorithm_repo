#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(auto &x : a)
        cin >> x;
    if(is_sorted(a.begin(),a.end()))
    {
        cout << "YES\n";
    }else 
    {
        if(k >= 2)
        {
            cout << "YES\n";
        }else 
        {
            cout << "NO\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}