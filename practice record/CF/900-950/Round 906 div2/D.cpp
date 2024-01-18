#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
ll pp[N];
ll id[N];
ll n,c;
bool cmp(ll x,ll y)
{
    return x * c - a[x] < y * c - a[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(ll i = 2;i <= n;++i)
        {
            id[i] = i;
            // cout << pp[i] << " ";
        }
        ll total = a[1];
        sort(id + 2,id + 1 + n,cmp);
        bool ok = 1;
        for(int i = 2;i <= n;++i)
        {
            if(total >= id[i] * c - a[id[i]])
            {
                total += a[id[i]];
            }else 
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            cout << "Yes\n";
        }else 
        {
            cout << "No\n";
        }
    }
}