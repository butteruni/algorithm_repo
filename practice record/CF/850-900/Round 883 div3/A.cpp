#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int t;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> a[i] >> b[i];
        int cnt = 0;
        for(int i = 1;i <= n;++i)
        {
            if(b[i] < a[i])
                cnt++;
        }
        cout << cnt << endl;
    }
}