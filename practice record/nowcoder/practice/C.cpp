#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        ll n,m,k;
        cin >> n >> m >> k;
        if(k == 1)
        {
            cout << m << '\n';
            continue;
        }
        ll t = k / 2; 
        ll mx = min(n,m / t);
        n -= mx;
        m -= mx * t;
        if(k & 1)
        {
            while(m * 2 + 1 >= k)
            {
                n --;
                m -= (k - 1) / 2;
                if(n == 0)
                    break;
            }
        }else 
        {
            n %= k;
            m %= (k / 2);
        }
        cout << (n / 2) + (n & 1) + m << '\n';
    }
}