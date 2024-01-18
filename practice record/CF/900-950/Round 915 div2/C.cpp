#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
struct node
{
    char op;
    int index;
};
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(is_sorted(s.begin(),s.end()))
    {
        cout << 0 << '\n';
        return ;
    }
    vector<node>p;
    int index = 0;
    for(int j = 'z';j >= 'a';--j)
    {
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == j && i >= index)
            {
                node cur;
                cur.index = i;
                cur.op = j;
                p.push_back(cur);
                index = i;
            }
        }
    }
    int ans = p.size();
    // cout << ans << endl;
    bool ok = 1;
    for(int i = 0;i < p.size() / 2;++i)
    {
        // cout << i << endl;
        int index1 = p[i].index;
        int index2 = p[ans - i - 1].index;
        swap(s[index1],s[index2]);
    }
    // cout << s << "\n";
    if(is_sorted(s.begin(),s.end()))
    {
        map<char,int>cnt;
        char mx = p[0].op;
        int st = 0;
        while(p[st].op == mx && st < p.size())
        {
            ans--,st++;
        }
        cout << ans << '\n';
    }else 
    {
        cout << -1 << '\n';
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