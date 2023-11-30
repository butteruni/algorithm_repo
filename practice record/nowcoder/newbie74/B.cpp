#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int pos = 1;
        if(n == 0)
            cout << 0 ;
        while(n)
        {
            if(n < pos * 2 + 1)
            {
                cout << n;
                n -= n;
                break;
            }
            cout << pos << " ";
            n -= pos;
            pos ++;
        }
        cout << "\n";
    }
}