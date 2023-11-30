#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

int n;
map<string,int>mp;
bool judge(string &str)
{
    for(int i = 0; i < str.size()-2; ++i)
    {
        if(str[i] == 'b' && str[i+1] == 'i' && str[i+2] == 'e')
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        bool flag = false;
        for(int j = 1; j <= m; ++j)
        {
            string str;
            cin >> str;
            if(judge(str) && !mp.count(str))
            {
                flag = true;
                cout << str << '\n';
                mp[str] = 1;
            }
        }
        if(!flag)
        {
            cout << "Time to play Genshin Impact, Teacher Rice!\n";
        }
    }
    return 0;
}