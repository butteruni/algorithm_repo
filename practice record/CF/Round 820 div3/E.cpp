#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    for(int i = 2;i <= 26;++i)
    {
        cout << "?" << 1 << " " << i << endl;
        ll x;
        cin >> x;
        cout << "?" << i << " " << 1 << endl;
        ll y;
        cin >> y;
        if(x == -1)
        {
            cout << "!" << i - 1 << '\n';
            break;
        }
        if(x != y)
        {
            cout << "!" << x + y << "\n";
        }
    }
}