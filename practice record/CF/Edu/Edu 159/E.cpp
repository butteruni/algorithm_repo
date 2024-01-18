#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 100;
int tr[N][30];
int idx;
ll sum[N];
ll ans;
void add(string x)
{
    int v = 0;
    sum[v]++;
    for(auto c:x)
    {
        int val = c - 'a';
        if(tr[v][val] == -1)
        {
            tr[v][val] = idx++;
        }
        v = tr[v][val];
        sum[v]++;
    }
}
void calc(string x)
{
    ll len = x.size();
    int v = 0;
    for(auto c: x)
    {
        int val = c - 'a';
        if(tr[v][val] == -1)
        {   
            ans += sum[v] * len;
            break;
        }else 
        {
            int ne = tr[v][val];
            ans += (sum[v] - sum[ne]) * len;
            len--;
            v = ne;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<string>s(n);
    idx = 1;
    memset(tr,-1,sizeof(tr));
    for(int i = 0;i < n;++i)
        cin >> s[i];
    for(int i = 0;i < n;++i)
    {
        add(s[i]);
    }
    for(int i = 0;i < n;++i)
    {
        reverse(s[i].begin(),s[i].end());
        calc(s[i]);
        // cout << ans << " ";
    }
    cout << ans * 2ll << '\n';
    // cout << idx << " ";
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