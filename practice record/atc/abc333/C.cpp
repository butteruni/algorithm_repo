#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 400;
// ll dp[N];
ll val[15];
map<ll,ll>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    // dp[1] = 3;
    val[1] = 1;
    for(int i = 2;i <= 13;++i)
    {
        val[i] = val[i - 1] * 10ll + 1;
    }
    for(int i = 1;i <= 13;++i)
    {
        for(int j = 1;j <= 13;++j)
        {
            for(int k = 1;k <= 13;++k)
            {
                mp[val[i] + val[j] + val[k]] = 1;
            }
        }
    }
    int cnt = 0;
    for(auto [x,val]:mp)
    {
        cnt++;
        if(cnt == n)
        {
            cout << x << '\n';
            break;
        }
    }
}