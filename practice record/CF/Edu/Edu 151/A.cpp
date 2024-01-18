#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,k,x;
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        bool success = 1;
        cin >> n >> k >> x;
        if(k == 2 && x == 1 && (n % 2 == 1) || (k == x && x == 1))
        {
            cout << "NO\n";
        }else 
        {
            cout << "YES" << "\n";
            if(x == 1)
            {
                int m = n / 2;
                cout << m << "\n";
                for(int i = 1;i < m;++i)
                {
                    cout << 2 << " ";
                }
                if(n & 1)
                    cout << 3 << "\n";
                else 
                    cout << 2 << "\n";
            }else 
            {
                cout << n << '\n';
                for(int i = 1;i <= n;++i)
                    cout << 1 << " ";
                cout << "\n";
            }
        }
    }
}