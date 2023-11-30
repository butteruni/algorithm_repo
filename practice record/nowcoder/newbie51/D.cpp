#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        if(n == 0 || n == 1)
        {
            cout << 0 << '\n';
            return 0;
        }
        ll sum = 0;
        vector<int>cnt;
        while(n)
        {
            int res = n % x;
            cnt.push_back(res);
            sum += res;
            n /= x;
        }
        cout << sum + cnt.size() << '\n';
        for(auto x:cnt)
        {
            for(int i = 1;i <= x;++x)
            {
                cout << 1 << " " << 'a' << '\n';
            }
            cout << 2 << " " << 'b' << '\n';
        }
    }

}