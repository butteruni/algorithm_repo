#include <bits/stdc++.h>
using namespace std;
map<char,int>cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cnt.clear();
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;
        int cur = 0;
        deque<int>pos[30];
        for(int i = 0;i < n;++i)
        {
            int u = a[i] - 'a';
            pos[u].push_back(i);
            while(cur < m && pos[b[cur] - 'a'].size() > 0)
            {
                int used = pos[b[cur] - 'a'].front();
                pos[b[cur] - 'a'].pop_front();
                for(int j = 0;j < b[cur] - 'a';++j)
                {
                    while(pos[j].size() && pos[j].front() < used)
                    {
                        pos[j].pop_front();
                    }
                }
                cur++;
            }
        }
        if(cur == m)
        {
            cout << "YES\n";
        }else 
        {
            cout << "NO\n";
        }
    }
}