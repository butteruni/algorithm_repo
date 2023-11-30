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
        ll a,b,c;
        cin >> a >> b >> c;
        ll calc1 = (a - 1);
        ll calc2 = abs(c - b) + c - 1;
        if(calc1 > calc2)
        {
            cout << 2 << '\n';
        }else if(calc1 == calc2)
        {
            cout << 3 << '\n';
        }else 
        {
            cout << 1 << '\n';
        }
    }
}