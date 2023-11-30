#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n % k == 0)
        {
            cout << 2 << "\n";
            cout << k + 1  << " " << n - (k + 1) << '\n';
        }else 
        {
            cout <<  1  << '\n';
            cout << n << '\n';
        }
    }
}