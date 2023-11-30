#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[100],b[100];
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        for(int i = 1;i <= m;++i)
            cin >> b[i];
        ll cnt_1 = 0,cnt_2 = 0;
        for(int i = 1;i <= n;++i)
            cnt_1 += a[i];
        for(int i = 1;i <= m;++i)
            cnt_2 += b[i];
        if(cnt_1 == cnt_2)
            cout << "Draw" << '\n';
        else if(cnt_1 > cnt_2)
            cout << "Tsondu" << '\n';
        else 
            cout << "Tenzing" << '\n';
    }
}