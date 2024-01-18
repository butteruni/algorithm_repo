#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e5 + 10;
ll a[N],id[N];
ll b[N];
ll pre[N];
bool cmp(int x,int y)
{
    return a[x] < a[y];
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1,id + 1 + n,cmp);
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        sum += a[id[i]];
        pre[id[i]] = sum;
    }
    for(int i = n;i >= 1;--i)
    {
        if(i == n)
            b[id[i]] = n - 1;
        else 
        {
            if(pre[id[i]] < a[id[i + 1]])
            {
                b[id[i]] = i - 1;
            }else 
            {
                b[id[i]] = b[id[i + 1]] ;
            }
        }
    }
    for(int i = 1;i <= n;++i)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
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