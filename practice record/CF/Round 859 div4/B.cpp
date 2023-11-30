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
        vector<int>a(n);
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            if(a[i] & 1)
            {
                sum1 += a[i];
            }else 
            {
                sum2 += a[i];
            }
        }
        if(sum1 >= sum2)
        {
            cout << "NO" << '\n';
        }else 
        {
            cout << "YES" << '\n';
        }
    }
}