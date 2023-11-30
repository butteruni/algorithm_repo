#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll val,ll k)
{
    ll sum = 0;
    while(val)
    {
        sum += val % 10;
        val /= 10;
    }
    return sum % k == 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll x,k;
        cin >> x >> k;
        for(ll i = x;i <= x + 20;++i)
        {
            if(check(i,k))
            {
                cout << i << '\n';
                break;
            }
        }
    }
}