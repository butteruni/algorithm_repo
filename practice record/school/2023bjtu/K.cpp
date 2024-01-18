#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    string s;
    cin >> s;
    vector<int>pos;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i] == '$')
            pos.push_back(i);
    }
    for(int i = 0;i < pos.size();i += 2)
    {
        for(int j = pos[i] + 1;j < pos[i + 1];++j)
        {
            cout << s[j];
        }
    }
    cout << '\n';
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