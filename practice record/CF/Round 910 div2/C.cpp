#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        if (k < n + m - 2 || (k + n + m) & 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    int x = (i + j) % 2;
                    if (i == 0 && j == 0)
                    {
                        x ^= 1;
                    }
                    cout << "RB"[x] << " \n"[j == m - 2];
                }
            }
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int x = (i + j) % 2;
                    if (i == 0 && j == 1)
                    {
                        x ^= 1;
                    }
                    cout << "RB"[x] << " \n"[j == m - 1];
                }
            }
        }
    }
}