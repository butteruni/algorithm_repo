#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N],b[N],c[N],id[N],d[N];
ll pre[N << 1];
bool cmp(int x,int y)
{
    return a[x] < a[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,x;
        cin >> n >> x;
        ll a_max = 0;
        ll a_min = 1e18;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            id[i] = i;
        }
        for(int i = 1;i <= 2 * n;++i)
            pre[i] = 0;
        sort(id + 1,id + 1 + n,cmp);
        for(int i = 1;i <= n;++i)
        {
            cin >> b[i];
            pre[b[i]]++;
        }
        for(int i = 1;i <= 2 * n;++i)
        {
            pre[i] += pre[i - 1];
        }
        if(x <= pre[id[n]]  && x >= pre[id[1]])
        {
            cout << "YES\n";
            int cnt = 0;
            for(int )
        }else 
        {
            cout << "NO\n";
        }
    }
}