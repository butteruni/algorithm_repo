#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll dp[N][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    // vector<ll>dp(n,0);
    vector<ll>op;
    ll sum = 0;
    ll sum1 = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        // cnt[i] = a[i] % 2;
        if(a[i] & 1)
        {
            op.push_back(a[i]);
            sum1 += a[i];
        }else 
        {
            sum += a[i];
        }
    }
    sort(op.begin(),op.end());
    if(op.size() & 1)
    {
        sum = sum + sum1 - op[0];
    }else 
    {
        sum += sum1;
    }
    cout << sum << '\n';
    
}