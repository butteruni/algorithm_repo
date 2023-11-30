#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
int x,y,n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> x >> y;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    int ans = 0;
    for(int i = n;i >= 1;--i)
    {
        if(a[i] > y)
                ans += 3;
        else 
            break;
    }
    cout << ans << endl;
}