#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t;
int n;
int cnt_1[N],cnt_2[N];
int ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        string s;
        cin >> s;
        for(int i = 1;i <= n;++i)
        {
            cnt_1[i] = cnt_1[i - 1];
            cnt_2[i] = cnt_2[i - 1];
            if(s[i - 1] == '(')
                cnt_1[i]++;
            else 
                cnt_2[i]++;
        }
        if(cnt_1[n] != cnt_2[n])
            cout << -1 << '\n';
        else 
        {
            int mn = N,mx = -N;
            for(int i = 1;i <= n;++i)
            {
                mn = min(cnt_1[i] - cnt_2[i],mn);
                mx = max(cnt_1[i] - cnt_2[i],mx);
            }
            if(mn == 0 || mx == 0)
            {
                cout << 1 << '\n';
                for(int i = 1;i <= n;++i)
                    cout << 1 << ' ';
                cout << '\n';
            }
            else
            {
                cout << 2 << '\n';
                int temp;
                if(s[0] == '(')
                {
                    temp = 1;
                }else 
                {
                    temp = 2;
                }
                for(int i = 1;i <= n;++i)
                {
                    cout << temp << " ";
                    if(cnt_1[i] == cnt_2[i])
                        temp = (s[i] == '(' ? 1: 2);
                }
                cout << '\n';
            }
        }
    }
}