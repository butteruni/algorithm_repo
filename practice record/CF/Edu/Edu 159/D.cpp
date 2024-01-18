#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N = 2e5 + 10;
ll dpx[N],dpy[N];
ll prex[N],prey[N];
map<PII,vector<int> >mp;

int n,q;

void solve()
{
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    mp[{0,0}].push_back(0);
    for(int i = 1;i <= n;++i)
    {
        if(s[i] == 'U')
            dpy[i] = 1;
        else if(s[i] == 'D')
            dpy[i] = -1;
        else if(s[i] == 'L')
            dpx[i] = -1;
        else if(s[i] == 'R')
            dpx[i] = 1;
        prex[i] = prex[i - 1] + dpx[i];
        prey[i] = prey[i - 1] + dpy[i];
        mp[{prex[i],prey[i]}].push_back(i);
    }
    for(int i = 1;i <= q;++i)
    {
        int x,y,l,r;
        cin >> x >> y >> l >> r;
        ll st_x = prex[l - 1],ed_x = prex[r];
        ll st_y = prey[l - 1],ed_y = prey[r];
        bool ok = 0;
        auto it = lower_bound(mp[{x,y}].begin(),mp[{x,y}].end(), 0); // l 左侧
        if(it != mp[{x,y}].end() && *it < l)
        {
            ok = 1;

        }
        it = lower_bound(mp[{x,y}].begin(),mp[{x,y}].end(), r); // r 右侧
        if(it != mp[{x,y}].end())
        {
            ok = 1;
            // cout << *it << " ";
        }
        ll dx = st_x + ed_x - x,dy = st_y + ed_y - y;
        // cout << ok << " ";
        it = lower_bound(mp[{dx,dy}].begin(),mp[{dx,dy}].end(),l); // l 和 r 之间
        if(it != mp[{dx,dy}].end() && *it <= r)
        {
            ok = 1;
        }
        if(ok)
        {
            cout << "Yes\n";
        }else 
        {
            cout << "No\n";
        }

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