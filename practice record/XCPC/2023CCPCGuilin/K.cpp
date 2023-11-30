#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll a[200];
double dfs(int val)
{
    if(val == 0)
        return 0;
    if(val == 10)
        return 0;
    return 0.5 * (dfs(val - 1) + 1.0) + 0.5 * (dfs(val + 1) + 1.0); 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    // int n,m;
    a[0] = 0;
    for(int i = 1;i <= 10;++i)
    {
        a[i] = 11 - 2 * i + a[i - 1];
    }
    // cout << dfs(1);  
    
    for(int i = 0;i <= 10;++i)
        cout << a[i] << " ";
}