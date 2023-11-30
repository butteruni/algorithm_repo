#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int mx1 = (b + c) + 1;
        if(mx1 > a)
        {
            cout << a + a - 1 << '\n';
        }else 
        {
            cout << mx1 + mx1 - 1 << '\n';
        }
    }

}