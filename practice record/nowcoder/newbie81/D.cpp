#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int m,a;
        cin >> m >> a;
        m -= a;
        int sum = 0,cnt = 0;
        for(int b = 1;b <= m;++b)
        {
            if(a % b == 0 || b % a == 0)
            {
                cnt++;
                sum += b;
            }
        }
        if(1.0 * sum / cnt > a)
        {
            cout << "YES\n";
        }else 
        {
            cout << "NO\n";
        }
    }
}