#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        sort(a + 1,a + 1 + n);
        ll gap = 0;
        vector<ll>ans;
        while(a[1] != a[n])
        {
            ll mid = (a[1] + a[n]) / 2;
            if((mid - a[1]) & 1)
                mid --;
            ans.push_back(mid);
            a[1] = (a[1] + mid) / 2;
            a[n] = (a[n] + mid) / 2;
        }
        cout << ans.size() << '\n';
        if(ans.size() <= n && ans.size())
        {
            for(auto x:ans)
                cout << x << ' ';
            cout << '\n';
        }
    }
}