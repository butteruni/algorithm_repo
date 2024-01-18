#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 2e5 + 10;
ll a[N],b[N];
struct node
{
    ll value;
    int idx;
}ls1[N],ls2[N];
map<int,int>vis;
bool cmp(node x,node y)
{
    return x.value > y.value;
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
        cin >> b[i];
    vis.clear();
    for(int i = 1;i <= n;++i)
    {
        ls1[i].value = b[i] + a[i];
        ls2[i].value = a[i] + b[i];
        ls1[i].idx = i;
        ls2[i].idx = i;
    }
    sort(ls1 + 1,ls1 + 1 + n,cmp);
    sort(ls2 + 1,ls2 + 1 + n,cmp);

    int l1 = 1,l2 = 1;
    for(int i = 1;i <= n;++i)
    {
        if(i & 1)
        {
            while(vis[ls1[l1].idx])
            {
                l1++;
            }
            a[ls1[l1].idx]--;
            b[ls1[l1].idx] = 0;
            vis[ls1[l1].idx] = 1;
        }else 
        {
            while(vis[ls2[l2].idx])
            {
                l2++;
            }
            a[ls2[l2].idx] = 0;
            b[ls2[l2].idx]--;
            vis[ls1[l2].idx] = 1;
        }
    }
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        sum += a[i];
        sum -= b[i];
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}