#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int r,l;
    cin >> r >> l;
    if((r && l) || (!r && !l))
    {
        cout << "Invalid\n";
        return;
    }else {
        if(r)
        {
            cout << "Yes\n";
        }else
            cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
}