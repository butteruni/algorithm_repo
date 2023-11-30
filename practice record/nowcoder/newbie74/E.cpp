#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int t,n,m,k,b;
ll h[N],a[N],cost_1[N],cost_2[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k >> b;
        m--;
        for(int i = 1;i <= n;++i)
        {
            cin >> h[i];
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;++i)
        {
            if(h[i] >= k)
                cost_1[i] = 1;
            else 
            {
                int dis = k - h[i];
                cost_1[i] = dis / a[i] + 1;
            }
        }
        for(int i = 1;i <= n;++i)
        {
            int dis = k - b;
            cost_2[i] = dis / a[i] + 1;
        }
        for(int i = 1;i <= n;++i)
        {
            if(m < cost_1[i])
                cout << h[i] + m * a[i] << " ";
            else if(m == cost_1[i])
                cout << b << ' ';
            else 
            {
                ll rest = m - cost_1[i];
                if(rest % cost_2[i] == 0)
                    cout << b << " ";
                else 
                {
                    ll grow = rest % cost_2[i];
                    cout << b + grow * a[i] << " ";
                }
            }
        }
        cout << '\n';
    }

}