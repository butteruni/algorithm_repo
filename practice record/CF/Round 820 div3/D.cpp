#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N = 2e5 + 10;
ll p[N];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int cnt_0 = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> p[i];
        }
        for(int i = 1;i <= n;++i)
        {
            ll x;
            cin >> x;
            p[i] = x - p[i];
            if(p[i] == 0)
                cnt_0++;
        }
        sort(p + 1,p + 1 + n,cmp);
        int r = n;
        int ans = 0;
        for(int l = 1;l <= n;l++)
        {
            while(r > l && p[l] + p[r] < 0)
                r--;
            if(r <= l)
                break;
            ans++,r--;
        }
        cout << ans << '\n';
    }
}