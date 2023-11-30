#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string n;
    cin >> n;
    int sz = n.size();
    bool ok = 0;
    for(int i = sz - 1;i >= 0 ;--i)
    {
        int x = n[i] - '0';
        if(x % 2 == 0)
        {
            ok = 1;
            cout << sz - 1 - i << '\n';
            break;
        }
    }
    if(!ok)
    {
        cout << sz << '\n';
    }
}