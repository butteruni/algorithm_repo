#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    bool ok = 0;
    for(ll i = 1;i * i * i * i <= n;++i)
    {
        
        if(n == (i * i * i * i * i - 1) / (i - 1))
        {   
            ok = 1;
            break;
        }
    }
    if(ok)
    {
        cout << "Yes\n";
    }else 
    {
        cout << "No\n";
    }
}