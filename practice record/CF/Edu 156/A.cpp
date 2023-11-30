#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n <= 6|| n == 9)
        {
            cout << "NO\n";
        }else 
        {
            cout << "YES\n";
            ll base = n / 3;
            ll a,b,c;
            a = base,b = base,c = base;
            if(n % 3 == 0)
            {
                cout << 1 << " " << 4 << " " << n - 5 << '\n'; 
            }else 
            {
                cout << 1 << " " << 2 << " " << n - 3 << '\n';
            }
        }
    }
}