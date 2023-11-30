#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>vis;
ll tmp = 1 << 20;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
       ll ans = 20;
       for(int i = 0;i <= 20;++i)
       {
            if(i != 0)
                n++;
            if(n % tmp == 0)
            {
                ans = min(ans,(ll)i);
            }else 
            {
                ll tmp = n;
                int cnt = 0;
                while(tmp % 2 == 0)
                {
                    cnt++;
                }
                ans = min(ans,(ll)i + 20 - cnt);
            }
       }
       cout << ans << '\n';
    }
}