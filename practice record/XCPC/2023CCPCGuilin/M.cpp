#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
ll a[N],b[N],c[N];
int n;
bool check(ll val)
{
    int cnt = 0;
    ll mx = 0;
    for(int i = 1;i <= n;++i)
    {
        if(a[i] >= val)
            cnt++;
        c[i] = (b[i] >= val) - (a[i] >= val);
        c[i] = max(c[i],c[i] + c[i - 1]);
        mx = max(mx,c[i]);
    }
    return cnt + mx >= (n + 1) / 2;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i] >> b[i];
    ll l = 0,r = 1e18;
    while(l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    cout << l << '\n';
}