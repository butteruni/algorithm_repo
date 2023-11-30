#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    bool ok = 0;
    int pre = n - 1;
    while(!ok)
    {
        int a,b,c;
        n = pre + 1;
        pre = n;
        c = n % 10;
        n /= 10;
        a = n % 10;
        n /= 10;
        b = n;
        if(a * b == c)
        {
            ok = 1;
        }
    }
    cout << pre << "\n";
}