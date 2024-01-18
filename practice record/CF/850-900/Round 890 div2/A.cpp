#include <bits/stdc++.h>
using namespace std;
const int N = 500;
typedef long long ll;
ll a[N];
ll mxn[N];
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
        memset(mxn,0,sizeof(mxn));
        bool unsort = 0;
        ll mx = 0;
        vector<int>pos;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            mx = max(mx,a[i]);
            if(a[i] < a[i - 1])
            {
                unsort = 1;
                pos.push_back(i);
                mxn[i] = mx;
                mx = 0;
            }
        }
        if(!unsort)
        {
            cout << 0 << '\n';
        }else 
        {
            ll ans = 0;
            for(int x:pos)
            {
                ans = max(mxn[x],ans);
            }
            cout << ans << "\n";
        }
    }
}