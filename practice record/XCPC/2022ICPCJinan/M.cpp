#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        vector<int>pos[20];
        for(int i = 1;i <= 18;++i)
            pos[i].clear();
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            int st = 1;
            while(a[i])
            {
                int x = a[i] % 10;
                pos[st].push_back(x);
                a[i] /= 10;
                st++;
            }
        }
        ll pre = 0;
        for(ll i = 1;i <= 18;++i)
        { 
            pre = 0;
            for(auto x:pos[i])
            {
                pre += x;
                if(pre > 9)
                {
                    pre -= 10;
                    ans++;
                    pos[i + 1].push_back(1);
                }
            }
        }
        cout << ans << '\n';
    }
}