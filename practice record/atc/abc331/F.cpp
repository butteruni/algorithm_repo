#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
ll n,q;
string s;
bool check(int l,int r)
{

}
void solve()
{
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    for(int i = 1;i <= q;++i)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int pos;
            char x;
            cin >> pos;
            cin >> x;
            


        }else 
        {
            int l,r;
            cin >> l >> r;
            if(check(l,r))
            {
                cout << "Yes\n";
            }else 
            {
                cout << "No\n";
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