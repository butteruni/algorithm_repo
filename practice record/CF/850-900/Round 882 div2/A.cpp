#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
int t,n,k;
int a[N];
int mins[N];
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        for(int i = 1;i < n;++i)
            mins[i] = abs(a[i + 1] - a[i]);
        // for(int i = 1;i <= n;++i)
        //     cout << mins[i] << " ";
        // cout << "\n";
        sort(mins + 1,mins + n);
        ll ans  = 0;
        k--;
        for(int i = n - 1;i >= 1;--i)
        {
            if(k)
                k--;
            else 
                ans += mins[i];
        }
        cout << ans << '\n';
    }
}