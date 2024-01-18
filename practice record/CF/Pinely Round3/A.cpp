#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
typedef pair<ll,ll>PLL;
map<int,int>mp;
void solve()
{
    int n;
    mp.clear();
    int cnt = 0;
    cin >> n;
    int x = 0,y = 0;
    while(n--)
    {
        int nx,ny;
        cin >> nx >> ny;
        if(ny < y)
        {
            if(!mp.count(1))
            {
                mp[1] = 1;
                cnt++;
            }
        }else if(ny > y)
        {
            if(!mp.count(2))
            {
                mp[2] = 1;
                cnt++;
            }
        }
        if(nx < x)
        {
            if(!mp.count(3))
            {
                mp[3] = 1;
                cnt++;
            }
        }else if(nx > x)
        {
            if(!mp.count(4))
            {
                mp[4] = 1;
                cnt++;
            }
        }
    }
    if(cnt <= 3)
    {
        cout << "YES\n";
    }else 
    {
        cout << "NO\n";
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