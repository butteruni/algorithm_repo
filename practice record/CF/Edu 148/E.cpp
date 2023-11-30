#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
const ll MOD = 998244353;
ll b[10][N];
ll n,a_1,x,y,m,k;
ll a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> a_1 >> x >> y >> m >> k;
    for(int i = 1;i <= n;++i)
    {
        if(i == 1)
            a[i] = a_1;
        else 
            a[i] = (a[i - 1] * x + y) % m;
    }
    for(int i = 1;i <= n;++i)
    {

        b[0][i] = (b[0][i - 1] + a[i]) % MOD;
    }
    for(int i = 1;i <= k;i++)
    {
        if(i > 1)
            b[i][1] = 0;
        else 
            b[i][1] = a[1];
        for(int j = 2;j <= n;j++)
        {
            b[i][j] = (((b[i][j - 1] + b[i - 1][j - 1]) % MOD) + MOD) % MOD ;
            if(i == 1)
            {
                b[i][j] += a[j];
            }
            b[i][j] = (b[i][j] % MOD + MOD) % MOD;
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ans ^=  b[k][i] * (ll)(i);
    }
    cout << ans << '\n';
}