#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 100;
char c[N][N];
void solve()
{
    int cnt = 0;
    for(int i = 1;i <= 5;++i)
    {
        for(int j = 1;j <= 5;++j)
        {
            cin >> c[i][j];
            if(c[i][j] == 'o')
                cnt++;
        }
    }
    if(cnt == 1)
    {
        cout << "Away\n";
    }else if(cnt == 2)
    {
        cout << "Far\n";
    }else if(cnt == 3)
    {
        cout << "Away\n";
    }else 
    {
        cout << "Away\n";
    }   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}