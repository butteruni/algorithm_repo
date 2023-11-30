#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
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
        bool success = 0;
        int cnt1 = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] % 2 == 1)
            {
                cnt1++;
            }
        }
        vector<int> pre(n + 1);
        if(cnt1 % 2 == 0)
        {
            cout << "YES" << '\n';
        }else 
        {
            cout << "NO" << '\n';
        }

    }
}