#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int st[N];
ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        if(n % k == 0)
        {
            cout << n / k << '\n';
            for(int i = 1;i <= n;i += k)
            {
                cout << i << " ";
            }
            cout << '\n';
        }else 
        {
            if(gcd(n,k) == 1)
            {
                cout << -1 << '\n';
            }else 
            {
                
            }
        }
    }
}