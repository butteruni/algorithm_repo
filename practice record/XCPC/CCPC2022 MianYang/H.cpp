#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    cout << n * 2 - 1 << '\n';
    cout << 150 << " " << 150 << '\n';
    int i = 150,j = 150;
    for(int cnt = 1;cnt < n;++cnt)
    {
        i--;
        cout << i << " " << i << '\n';
        j++;
        cout << j << " " << j << '\n';
    }
}