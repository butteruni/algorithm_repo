#include  <bits/stdc++.h>
using namespace std;
int n;
char x;
int pre;
int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string s;
        cin >> s;
        s = " " + s; 
        int ans = 0;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 1;i <= n;++i)
        {
            if(s[i] == '>')
            {
                cnt1++;
                ans = max(cnt1,max(ans,cnt2));
                cnt2 = 0;
            }
            else 
            {
                cnt2++;
                ans = max(cnt1,max(ans,cnt2));
                cnt1 = 0;
            }
            // cout << ans + 1 << "|";
        }
        cout << ans + 1<< '\n';
    }
}