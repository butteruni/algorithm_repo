#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
vector<ll>a(N);
vector<ll>b(N);
bool cmp(int x,int y)
{
    return b[x] < b[y];
}
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
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        for(int i = 1;i <= n;++i)
            cin >> b[i];
        ll ans = 0;
        ll mx = 0,mn = 1e9;
        for(int i = 1;i <= n;++i)
        {
            ans += abs(a[i] - b[i]);
            mx = max(mx,min(a[i],b[i]));
            mn = min(mn,max(a[i],b[i]));
        }
        ll add = 0;
        for(int i = 1;i <= n;++i)
        {
            if(mx > max(a[i],b[i]))
            {
                add = max(add,(mx - max(a[i],b[i])) * 2);
            }
            if(mx < min(a[i],b[i]))
            {
                add = max(add,(min(a[i],b[i]) - mn) * 2);
            }
        }
        cout << ans + add << '\n';
    }
}