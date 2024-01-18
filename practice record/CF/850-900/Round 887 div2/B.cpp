#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll a,ll b,ll cnt)
{
    if(cnt <= 0)
        return 1;
    if(b - a <= a && b - a >= 0)
    {
        return check(b - a,a,cnt - 1);
    }else 
    {
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        if(k > 50)
        {
            cout << 0 << '\n';
        }else 
        {
            int cnt = 0;
            for(int i = 0;i <= n / 2;++i)
            {
                if(check(i,n - i,k - 3))
                    cnt++;
            }
            cout << cnt << '\n';
        }
        
    }

    return 0;
}

