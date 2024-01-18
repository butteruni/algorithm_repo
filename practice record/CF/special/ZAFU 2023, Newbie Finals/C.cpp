#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll a[N],b[N];
bool cmp(ll x,ll y)
{
    return x > y;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= m;++i)
        cin >> b[i];
    sort(a + 1,a + 1 + n,cmp);
    sort(b + 1,b + 1 + m,cmp);
    for(int i = 1;i <= max(n,m);++i)
    {
        if(a[i] > b[i])
        {
            cout << "guanmiantang_h" << '\n';
            return ;
        }else if(a[i] < b[i])
        {
            cout << "Arctic_Bake" << '\n';
            return;
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
        int n,m;
        cin >> n >> m;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        for(int i = 1;i <= m;++i)
            cin >> b[i];
        sort(a + 1,a + 1 + n,cmp);
        sort(b + 1,b + 1 + m,cmp);
        for(int i = 1;i <= max(n,m);++i)
        {
            if(a[i] > b[i])
            {
                cout << "guanmiantang_h" << '\n';
                break;
            }else if(a[i] < b[i])
            {
                cout << "Arctic_Bake" << '\n';
                break;
            }
        }
    }
}