#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    string s;
    getline(cin,s);
    // cout << s << '\n';
    // cout << s.find("You are right, but") << '\n';
    if(s.find("You are right, but") == 0)
    {
        cout << "AI\n";
    }else 
    {
        cout << "Human\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}