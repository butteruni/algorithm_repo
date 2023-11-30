#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x : a)
        cin >> x;
    sort(a.begin(),a.end());
    int mx = a.back();
    bool ok = 0;
    for(int i = a.size() - 1;i >= 0;--i)
    {
        if(a[i] != mx)
        {
            ok = 1;
            cout << a[i] << "\n";
            break;
        }
    }
    assert(ok == 1);
}