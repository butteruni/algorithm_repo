#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
struct node
{
    ll a,b;
    ll val;
}ls[5050];
bool cmp(node x,node y)
{
    return x.val > y.val;
}
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> ls[i].a >> ls[i].b;
        ls[i].val = ls[i].a + ls[i].b;
        sum += ls[i].a;
    }
    sort(ls + 1,ls + 1 + n,cmp);
    for(int i = 1;i <= n;++i)
    {
        sum -= ls[i].a;
        sum -= ls[i].b;
        if(sum <= 0)
        {
            cout << i << '\n';
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}