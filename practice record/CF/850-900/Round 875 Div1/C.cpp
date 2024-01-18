#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
typedef pair<ll,ll>PLL;
const int N = 3e5 + 10;
int po[N];
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
        ll ans = 1;
        bool ok = 1;
        for(int i = 0;i <= n;++i)
            po[i] = 0;
        for(int i = 1;i <= k;++i)
        {
            int l,r;
            cin >> l >> r;
            po[l]++;
            po[r + 1] --;
        }
        for(int i = 1;i <= n;++i)
            po[i] += po[i - 1];
        for(int i = 1;i <= n;++i)
        {
            if(po[i] == 0)
                ans = ans * 2 % mod;
            
        }
        if(!ok)
        {
            cout << 0 << "\n";
        }else 
        {
            cout << ans << '\n';
        }
    }
}