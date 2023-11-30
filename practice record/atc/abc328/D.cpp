#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
// int pos[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    deque<int>pos;
    for(int i = 1;i <= n;i ++)
    {
        if(pos.size())
        {
            if(s[pos.back()] == 'A')
            {
                if(i + 1 <= n)
                {
                    if(s[i] == 'B' && s[i + 1] == 'C')
                    {
                        i++;
                        pos.pop_back();
                    }else 
                    {
                        pos.push_back(i);
                    }
                }else 
                {
                    pos.push_back(i);
                }
            }else if(s[pos.back()] == 'B')
            {
                int p = pos.back();
                pos.pop_back();
                if(!pos.empty() && s[pos.back()] == 'A' && s[i] == 'C')
                {
                    pos.pop_back();
                }else 
                {
                    pos.push_back(p);
                    pos.push_back(i);
                }
            }else 
            {
                pos.push_back(i);
            }
        }else
        {
            pos.push_back(i);
        }
    }
    if(pos.size())
    {
        for(auto x : pos)
        {
            cout << s[x];
        }
        cout << '\n';
    }
}