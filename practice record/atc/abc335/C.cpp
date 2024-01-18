#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
int dx[N],dy[N];
void solve()
{
    int n,q;
    cin >> n >> q;
    int cnt = 0;
    // int dx = 0,dy = 0;
    dx[0] = 1;
    for(int i = 1;i <= q;++i)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            cnt++;
            dy[cnt] += dy[cnt - 1];
            dx[cnt] += dx[cnt - 1];
            char x;
            cin >> x;
            if(x == 'U')
                dy[cnt] += 1;
            else if(x == 'D')
                dy[cnt] += -1;
            else if(x == 'L')
                dx[cnt] += -1;
            else if(x == 'R')
                dx[cnt] += 1;
            
        }else 
        {
            int pos;
            cin >> pos;
            if(pos > cnt)
            {
                cout << pos - cnt << ' ' << 0 << '\n';
            }else 
            {
                int mov = cnt - pos + 1;
                // cout << mov <<"  ";
                cout << dx[mov] << " " << dy[mov] << '\n';
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}