#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        vector<int>a(n);
        vector<int>aft(n);
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            aft[i] = a[i];
        } 
        for(int i = n - 1;i >= 1;--i)
        {
            if((a[i - 1] + a[i]) % 2 != 0)
            {
                aft[i - 1] = max(aft[i - 1],aft[i - 1] + aft[i]); 
            }
        }
        ll ans = -1e18;
        for(int i = 0;i < n;++i)
            ans = max(ans,(ll)aft[i]);
        cout << ans << '\n';
    }
}