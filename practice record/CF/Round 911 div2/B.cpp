#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];
ll b[4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> b[1] >> b[2] >> b[3];
        for(int i = 1;i <= 3;++i)
        {
            bool ok = 0;
            if(i == 1)
            {
                if(abs(b[2] - b[3]) % 2 == 0)
                {
                    ok = 1;
                }
            }
            if(i == 2)
            {
                if(abs(b[1] - b[3]) % 2 == 0)
                {
                    ok = 1;
                }
            }
            if(i == 3)
            {
                if(abs(b[1] - b[2]) % 2 == 0)
                    ok = 1;
            }
            if(ok)
            {
                cout << "1 ";
            }else 
            {
                cout << "0 ";
            }
        }
        cout << '\n';
    }
}