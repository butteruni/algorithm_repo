#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int cnt[N];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        sort(a + 1 ,a + 1 + n);
        memset(cnt,0,sizeof(cnt));
        for(int i = 1;i <= n;++i)
        {
            cnt[a[i]]++;
        }
        int success = 1;
        for(int i = a[1];i <= a[n];++i)
        {
            if(cnt[i] < cnt[i + 1])
            {
                success = 0;
                break;
            }
        }
        if(a[1] != 0)
            success = 0;
        if(success)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
}