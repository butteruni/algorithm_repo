#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N],b[N];
int n,m;
bool check(ll x)
{
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    for(int i = 1;i <= n;++i)
    {
        if(a[i] <= x)
            cnt1++;
    }
    for(int i = 1;i <= m;++i)
    {
        if(b[i] >= x)
            cnt2++;
    }
    return cnt1 >= cnt2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;++i)
    {
        cin >> b[i];
    }
    ll l = 0,r = 1e10;
    while(l < r)
    {
        ll mid = (l + r )>> 1;
        if(check(mid))
            r = mid;
        else 
            l = mid + 1;
    }  
    cout << l << endl;
}