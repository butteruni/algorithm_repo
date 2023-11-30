#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(double val)
{
    cout << fixed << setprecision(8) << val << ' ';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    double ans = 1.0 * sum / (n + 1);
    for(int i = 0;i < n;++i)
    {
        if(i == 0)
            print(ans * 2.0);
        else
            print(ans);
        cout << '\n';
    }
    cout << '\n';
}