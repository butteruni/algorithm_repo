#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
ll emp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        if(a[1] != 1)
        {
            cout << 1 << '\n';
            continue;
        }
        for(int i = 1;i <= n;++i)
        {
            emp[i] = a[i] - a[i - 1] - 1;
            emp[i] += emp[i - 1];
        }
        ll ans = 1;
        ll add = 1;
        for(int i = 1;i <= k;++i)
        {   
            while(add < n && emp[add + 1] < ans)
            {
                add++;
            }
            ans += add;
        }
        cout << ans << '\n';
    }
}