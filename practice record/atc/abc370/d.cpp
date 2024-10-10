#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;

void solve()
{
    int h,w,q;
    cin >> h >> w >> q;
    ll ans = h * w;
    vector<set<int>>col;
    vector<set<int>>arr;
    for(int i = 0;i <= h;++i)
    {
        set<int>tmp;
        for(int j = 0;j <= w + 1;++j)
            tmp.insert(j);
        col.push_back(tmp);
    }
    for(int i = 0;i <= w;++i)
    {
        set<int>tmp;
        for(int j = 0;j <= h + 1;++j)
            tmp.insert(j);
        arr.push_back(tmp);
    }
    for(int i = 1;i <= q;++i)
    {
        int r,c;
        cin >> r >> c;
        if(col[r].count(c) && arr[c].count(r))
        {
            col[r].erase(c);
            arr[c].erase(r);
            ans--;
            continue;
        }
        auto it = col[r].lower_bound(c);
        if(it != col[r].begin())
        {
            --it;
            int val = *it;
            if(val >= 1)
            {
                col[r].erase(val);
                arr[val].erase(r);
                ans--;
            }
        }
        it = col[r].upper_bound(c);
        if(it != col[r].end())
        {
            int val = *it;
            if(val <= w)
            {
                col[r].erase(val);
                arr[val].erase(r);
                ans--;

            }

        }
        it = arr[c].lower_bound(r);
        if(it != arr[c].begin())
        {
            --it;
            int val = *it;
            if(val >= 1)
            {
                arr[c].erase(val);
                col[val].erase(c);
                ans--;
            }
        }
        it = arr[c].upper_bound(r);
        if(it != arr[c].end())
        {
            int val = *it;
            if(val <= h)
            {

                arr[c].erase(val);
                col[val].erase(c);
                // cout << val << "||" << c << '\n';
                ans--;
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
}