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
        int n;
        cin >> n;
        if(n == 1 || n == 3)
        {
            cout << -1 << '\n';
        }else 
        {
            int cur = n;
            for(int i = 1;i <= n / 2;++i)
            {
                cout << cur << ' ';
                cur--;
            }
            int st = 1;
            for(int i = n / 2 + 1;i <= n;++i)
            {
                cout << st << " ";
                st++;
            }
            cout << "\n";
        }
    }
}