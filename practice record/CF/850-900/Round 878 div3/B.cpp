#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll x = n;
        ll cnt = 0;
        int temp = 1;
        if(k > 30)
            cout << n + 1 << '\n';
        else 
            cout << min(n + 1,1ll << k) << '\n';
    }
}