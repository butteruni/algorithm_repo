#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int lose(char a,char b)
{
    if(a == b)
    {
        return 2;
    }
    if(a == 'S')
    {
        if(b == 'R')
            return 0;
        return 1;
    }else if(a == 'P') 
    {
        if(b == 'S')
            return 0;
        return 1; 
    }else if(a == 'R')
    {
        if(b == 'P')
            return 0;
        return 1;
    }
}
ll dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        s = " " + s;
        int n = s.size();
        int ans = 0;
        int mx = -1;
        int pos = 1;
        for(int i = 2;i < n;++i)
        {
            int x = lose(s[i], s[i - 1]);
            if(x == 0)
            {
                ans--;
            }else if(x == 1)
            {
                ans++;
            }
            if(ans > mx)
            {
                pos = i;
                mx = ans;
            }
        }
        cout << s[pos] << '\n';
    }
}