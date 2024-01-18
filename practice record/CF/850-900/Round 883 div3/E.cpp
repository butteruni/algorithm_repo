#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 1e18;
int t;
ll n;
void check(ll x)
{
    for(int i = 2;i <= 62;++i)
    {
        ll l = 2,r = 1e9;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            ll sum = 0,m = 1;
            bool over = 0;
            for(int j = 0;j <= i;++j)
            {
                if(MX - sum < m)
                {
                    over = 1;
                    break;
                }
                sum += m;
                if(MX / m < mid && j < i)
                {
                    over = 1;
                    break;   
                }
                m *= mid;
            }
            if(sum == x)
            {
                cout << "YES" << endl;
                return;
            }else if(sum > x || over)
            {
                r = mid;
            }else if(sum < x)
            {
                l = mid + 1;
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        check(n);
    }
}