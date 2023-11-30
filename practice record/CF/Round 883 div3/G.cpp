#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1 << 10;
int dis[N];
int t,n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(dis,0x3f,sizeof(dis));
        bitset<10> tmp;
        cin >> tmp;
        int st = (int)tmp.to_ulong();
        vector<pair<PII,int> > edge;
        edge.resize(m + 1);
        for(int i = 1;i <= m;++i)
        {
            cin >> edge[i].second;
            cin >> tmp;
            edge[i].first.first = ((1 << n) - 1) ^ (int)(tmp.to_ulong());
            cin >> tmp;
            edge[i].first.second = (int)(tmp.to_ulong());
        }
        dis[st] = 0;
        set<PII> q ;
        q.insert({0,st});
        while(q.size())
        {
            auto temp = *q.begin();
            q.erase(temp);
            for(int i = 1;i <= m;++i)
            {
                int ne = temp.second & edge[i].first.first;
                ne |= edge[i].first.second;
                if(dis[ne] > temp.first + edge[i].second)
                {
                    q.erase({dis[ne],ne});
                    dis[ne] = temp.first + edge[i].second;
                    q.insert({dis[ne],ne});
                }
            }
        }
        if(dis[0] > 1e8)
            cout << "-1" << '\n';
        else 
            cout << dis[0] << '\n';
    }
    // cout << endl;
}