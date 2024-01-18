#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int t,n,m,q;
int l[N],r[N];
int cnt[N];
int temp[N];
int x;
bool check(int x)
{
    memset(temp,0,sizeof(temp));
    for(int i = 1;i <= x;++i)
    {
        temp[cnt[i]]++;
    }
    for(int i = 1;i <= n;++i)
        temp[i] += temp[i - 1];
    for(int i = 1;i <= m;++i)
    {
        if(temp[r[i]] - temp[l[i] - 1] > (r[i] - l[i] + 1) / 2)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    { 
        cin >> n >> m;
        for(int i = 1;i <= m;++i)
        {
            cin >> l[i] >> r[i];
        }
        cin >> q;
        memset(cnt,0,sizeof(cnt));
        ll ans = 0;
        for(int i = 1;i <= q;++i)
        {
            cin >> cnt[i];
        }
        int l = 1,r = q + 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid))
            {
                r = mid ;
            }else 
                l = mid + 1;
        }
        if(l == q + 1)
            l = -1;
        cout << l << '\n';
    }
}