#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll mod = 998244353;
const int N = 2e5 + 10;
map<string ,int>vis;
ll cnt;
void dfs(int val,string s)
{
    if(s.size() == val)
    {
        for(int i = 0;i + 2 < s.size();++i)
        {
            if(s[i] == 't' && s[i + 1] == 'x' && s[i + 2] == 't')
            {
                cnt++;
                // cout << s << "\n";
                break;
            }
        }
        return;
    }
    for(int i = 0;i < 26;++i)
    {
        char x = 'a' + i;
        string tmp = s + x;
        dfs(val,tmp);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i = 7;i <= 7;++i)
    {   
        cnt = 0;
        vis.clear();
        dfs(i,"");
        cout << cnt << endl;
    }
}