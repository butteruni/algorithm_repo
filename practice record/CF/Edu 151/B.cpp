#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
int t;
int xa,ya,xb,yb,xc,yc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        int ans_x = 0,ans_y = 0;
        if(xb > xc)
        {
            swap(xb,xc);
        }
        // cout << xa << " " << xb << " " << xc << '\n';
        // cout << (xa <= xb) << '\n';
        if(xb <= xa && xa <= xc)
        {
            ans_x = 0;
        }else 
        {
            if(xa <= xb)
            {
                // cout << t << '\n';
                ans_x = xb - xa;
            }else
            {
                ans_x = xa - xc;
            }
        }
        if(yb > yc)
            swap(yb,yc);
        if(yb <= ya && ya <= yc)
        {
            ans_y = 0;
        }else 
        {
            if(ya <= yb)
            {
                ans_y = yb - ya;
            }else
            {
                ans_y = ya - yc;
            }
        }
        cout << ans_x + ans_y + 1 << '\n';
    }
}