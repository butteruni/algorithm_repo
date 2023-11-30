#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
ll a[N],b[N];
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
        ll m = n * (n - 1) / 2;
        for(int i = 1;i <= m;++i)
        {
            cin >> b[i];
        }
        sort(b + 1,b + 1 + m);
        int pos = 1;
        for(int i = 1;i <= n;++i)
        {
            a[i] = b[pos];
            if(i != n - 1)
                pos += (n - i);
        }
        // cout << pos << " ";
        for(int i = 1;i <= n;++i)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}