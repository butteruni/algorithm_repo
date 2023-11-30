#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll expect = 6;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    n %= 10;
    ll ans = 6 * n;
    ans = ans % 10;
    // cout << ans << "\n";
    if(ans == 2 || ans == 8)
    {
        for(int i = 1;i <= min((ll)2,m);++i)
        {
            ans = ans * ans;
            ans %= 10;
        }    
    }else if(ans == 7 || ans == 3)
    {
        for(int i = 1;i <= min((ll)2,m);++i)
        {
            ans = ans * ans;
            ans %= 10;
        }
    }else if(ans == 4 || ans == 9)
    {
        for(int i = 1;i <= min((ll)1,m);++i)
        {
            ans = ans * ans;
            ans %= 10;
        }
    }
    cout << ans << '\n';

}