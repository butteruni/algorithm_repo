#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll c[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll ans = 0;
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> c[i];
        for(int i = 1;i <= n;++i)
        {
            if(c[i] > c[i - 1])
                ans += c[i] - c[i - 1];
        }
        cout << ans - 1 << '\n';
        
    }
}