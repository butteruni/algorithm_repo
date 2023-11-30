#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int t,n,m;
ll a[N];
ll attri[N];
ll sum = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        sum = 0;
        memset(attri,0,sizeof(attri));
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            sum += a[i];
            attri[i] = -a[i] * ((n - i) + 1);
        }
        sort(attri + 1,attri + 1 + n);
        for(int i = 1;i <= m;++i)
        {
            if(attri[i] > 0)
                break;
            sum += attri[i];
        }
        cout << sum << endl;
    }

}