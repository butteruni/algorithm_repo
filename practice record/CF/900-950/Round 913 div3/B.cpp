#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
typedef pair<char,int>Pll;
ll vis[N];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    deque<Pll>pos_A;
    deque<Pll>pos_a;
    for(int i = 1;i <= n;++i)
    {
        auto x = make_pair(s[i],i);
        if(s[i] == 'B')
        {
            if(pos_A.size())
            {
                pos_A.pop_back();
            }
        }else if(s[i] == 'b')
        {
            if(pos_a.size())
            {
                pos_a.pop_back();
            }
        }else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            pos_A.push_back(x);
        }else 
        {
            pos_a.push_back(x);
        }
    }
    while(pos_a.size() && pos_A.size())
    {
        auto a = pos_a.front();
        auto A = pos_A.front();
        if(a.second < A.second)
        {
            cout << a.first;
            pos_a.pop_front();
        }else 
        {
            cout << A.first;
            pos_A.pop_front();
        }
    }
    while(pos_a.size())
    {
        auto a = pos_a.front();
        cout << a.first;
        pos_a.pop_front();
    }
    while(pos_A.size())
    {
        auto A = pos_A.front();
        cout << A.first;
        pos_A.pop_front();
    }
    cout << '\n';
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