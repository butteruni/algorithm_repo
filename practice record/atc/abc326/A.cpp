#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int x,y;
    cin >> x >> y;
    if(y > x + 2 || y < x - 3)
    {
        cout << "No\n";
    }else 
    {
        cout << "Yes\n";
    }
}