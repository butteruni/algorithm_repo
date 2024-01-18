#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll c[N];
int n;
int t,a,b;
ll pre[N];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> c[i];
        ll mx = -1e9;
        for(int i = 1;i <= n;++i)
            mx = max(mx,c[i]);
        if(mx < 0)
            cout << mx << '\n';
        else 
        {
            ll ans_1,ans_2;
            ans_1 = 0;ans_2 = 0;
            for(int i = 1;i <= n;++i)
            {
                if(c[i] > 0)
                {
                    if(i & 1)
                        ans_1 += c[i];
                    else 
                        ans_2 += c[i];
                }
            }
            cout << max(ans_1,ans_2) << '\n';
        }
    }
}