#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
const int MX = 1e9;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll>a(n + 1);
        int cnt = 0;
        ll sum = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 1)
                cnt++;
        }
        if(sum >= n + cnt && n != 1)
        {
            cout << "YES" << '\n';
        }else 
        {
            cout << "NO" << '\n';
        }
    }
}