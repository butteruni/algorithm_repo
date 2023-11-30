#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2010;
char s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // string s;
        // cin >> s;
        // s = " " + s;
        for(int i = 1000;i < 1000 + n;++i)
        {
            cin >> s[i];
        }
        if(n & 1)
        {
            cout << "-1" << "\n";
            continue;
        }
        vector<int>ans;
        int ll = 0,rr = n;
        int l = 1000,r = 999 + n;
        int add1 = 0;
        int ok = 1;
        for(int i = l;i <= 999 + (n + add1) / 2;++i)
        {
            if(add1 >= 600)
            {
                ok = 0;
                break;
            }
            if(s[l] == s[r])
            {
                if(s[l] == '0')
                {
                    add1 += 2;
                    ans.push_back(rr);
                    ll++,rr++;
                    l++,r++;
                    s[r] = '0';
                }else 
                {
                    ans.push_back(ll);
                    add1+=2;
                    ll++,rr++;
                    r--;
                    l--;
                    s[l] = '1';
                }   
            }else 
            {
                l++,r--;
                ll++,rr--;
            }
        }

        if(ans.size() > 300 || !ok)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << "\n";
        for(auto x:ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}