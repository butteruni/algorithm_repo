#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 10;
int cnt;
bool vis[N];
ll pri[N];
ll mx = 1e18;
void init()
{
    vis[1]=1;
    for(int i=2;i<=N;i++) 
    {
        if(!vis[i])//如果没有被筛过就是质数
        {
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++) 
        {
            if(1ll*i*pri[j]>N)break;
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) 
            {
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--)
    {
        ll c;
        cin >> c;
        bool ok = 0;
        ll tmp = sqrtl(c);
        for(ll j = -2;j <= 2;++j)
        {
            if(tmp + j <= 1)
                continue;
            if((tmp + j) * (tmp + j) == c)
            {
                ok = 1;
            }
        }
        for(ll i = 1;pri[i] * pri[i] <= c && i <= cnt && !ok;++i)
        {
            if(c % (pri[i] * pri[i]) == 0)
            {
                ok = 1;
            }else if(c % pri[i] == 0)
            {
                c /= pri[i];
                ll tmp = sqrtl(c);
                for(ll j = -2;j <= 2;++j)
                {
                    if(tmp + j <= 1)
                        continue;
                    if((tmp + j) * (tmp + j) == c)
                    {
                        ok = 1;
                    }
                }
            }
        }
        if(c > 1)
        {
            ll tmp = sqrtl(c);
            if(tmp * tmp == c)
            {
                ok = 1;
            }
        }
    
        if(!ok)
        {
            cout << "no" << '\n';
        }else 
        {
            cout << "yes" << '\n';
        }

    }
}