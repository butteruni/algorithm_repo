#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> x >> y >> z;
    cout << x + min(y,z) << endl;
}