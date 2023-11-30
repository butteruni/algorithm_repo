#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int t,n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int cnt = 0;
        while(n >= 1)
        {
            cnt++;
            n /= 2;
        }
        cout << cnt << endl;
    }
}