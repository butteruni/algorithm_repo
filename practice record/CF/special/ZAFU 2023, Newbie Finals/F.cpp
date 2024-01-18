#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
struct node
{
    ll h,attack,idx;
    ll value;
}a[N];
bool cmp(node x,node y)
{
    return x.value > y.value;
}
void solve()
{
    int n;
    cin >> n;
    int ne = 0;
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i].h >> a[i].attack >> a[i].idx;
        a[i].value = a[i].h + a[i].attack;
        if(a[i].idx == 1)
            ne++;
        sum += a[i].h;
    }
    ne %= 2;
    sort(a + 1,a + 1 + n,cmp);
    if(ne)
    {
        // cout << sum << " " << a[n].value << "\n";
        sum -= a[n].value;
    }
    if(sum <= 0)
    {
        cout << -1 << '\n';
    }else 
    {
        cout << sum << '\n';
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