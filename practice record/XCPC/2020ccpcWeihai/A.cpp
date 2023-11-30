#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ll n,x,t;
        cin >> n >> x >> t;
        cout << min(2ll * n * t + 
        max(2ll * n * t, 2ll * t + x),
        2ll * n * t + max(2ll * n * t + t, t + x)) << "\n";
    }
}