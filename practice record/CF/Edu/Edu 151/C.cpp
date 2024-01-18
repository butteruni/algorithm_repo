#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int m;
int t;
string s,l,r;
int cnt[10][10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> s >> m >> l >> r;
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < m;++i)
        {
            for(int j = l[i] - '0';j <= r[i] - '0';++j)
                cnt[i][j] = 1;
        }
        int pos_l = 0;
        // for(int i = 0;i <= m;++i)
        // {
        //     for(int j = 0;j <= 9;++j)
        //         cout << cnt[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << m << '\n';
        int pos = 0;
        int i = 0;
        for(i = 0;i < m;++i)
        {
            int diffs = r[i] - l[i] + 1;
            while(diffs && pos < s.size())
            {
                if(cnt[i][s[pos] - '0'] == 1 )
                {
                    cnt[i][s[pos] - '0'] = 0;
                    diffs --;
                }
                pos++;
            }
            if(diffs)
                break;
        }
        if(i != m)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
}