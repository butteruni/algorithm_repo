#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e5 + 10;
ll a[N];
vector<ll>e[N];
bool vis[N];

string s;
vector<int> ans;
ll in[N];
void solve()
{
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    for(int i = 1;i <= n;++i)
    {
        e[i].clear();
        vis[i] = 0;
        in[i] = 0;
    }
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        e[i].push_back(a[i]);
        e[a[i]].push_back(i);
        in[i]++;
        in[a[i]]++;
    }
    bool ok = 1;
    for(int i = 1;i <= n;++i)
    {
        cout << s[i] << " " << in[i] << "\n";
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