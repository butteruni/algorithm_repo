#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<int,int>mp;
void solve()
{
    int n,m;
    cin >> n >> m;
    int cnt_w = 0,cnt_r = 0;
    for(int i = 1;i <= m;++i)
    {
        int w,r;
        cin >> r >> w;
        cnt_w = max(cnt_w,w);
        cnt_r = max(cnt_r,r);
    }
    if(cnt_r + cnt_w > n)
    {
        cout << "IMPOSSIBLE\n";
    }else 
    {
        for(int i = 1;i <= cnt_w;++i)
        {
            cout << "W";
        }
        for(int i = 1;i <= cnt_r;++i)
        {
            cout << "R";
        }
        for(int i = 1;i <= n - cnt_w -cnt_r;++i)
        {
            cout << "R";
        }
        cout << '\n';
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