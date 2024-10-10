#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    string s,t;
    cin >> s >> t;
    vector<int>pos1;
    vector<int>pos2;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i] > t[i])
            pos1.push_back(i);
        else if(s[i] < t[i])
            pos2.push_back(i);
    } 
    cout << pos1.size() + pos2.size() << '\n';
    for(int i = 0;i < pos1.size();++i)
    {
        int p = pos1[i];
        s[p] = t[p];
        cout << s << '\n';
    }
    for(int i = pos2.size() - 1;i >= 0;--i)
    {
        int p = pos2[i];
        s[p] = t[p];
        cout << s << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
}