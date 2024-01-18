#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
int dp_mx[N],dp_mn[N],mx[N],mn[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int cnt = 1;
        memset(dp_mx,-0x3f3f3f3f,sizeof(dp_mx));
        memset(dp_mn,0x3f3f3f3f,sizeof(dp_mn));
        memset(mx,-0x3f3f3f3f,sizeof(mx));
        memset(mn,0x3f3f3f3f,sizeof(mn));
        dp_mx[1] = dp_mn[1] = mx[1] = 1;
        mn[1] = 0;
        for(int i = 1;i <= n;++i)
        {
            char op;
            cin >> op;
            if(op == '+')
            {
                int v,x;
                cin >> v >> x;
                cnt++;
                dp_mx[cnt] = max(dp_mx[v] + x,x);
                dp_mn[cnt] = min(dp_mn[v] + x,x);
                mx[cnt] = max(mx[v],dp_mx[cnt]);
                mn[cnt] = min(dp_mn[cnt],mn[v] );
            }else 
            {
                int u,v,k;
                cin >> u >> v >> k;
                // cout << mx[v] << " " << mn[v] << '\n';
                if(k <= mx[v] && k >= mn[v])
                {
                    cout << "YES" << '\n';
                }else 
                {
                    cout << "NO" << '\n';
                }
            }
        }
    }
}