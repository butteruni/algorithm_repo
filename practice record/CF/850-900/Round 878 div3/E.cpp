#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,q;
string s[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s[0] >> s[1];
        int t, q;
        n = s[0].length();
        cin >> t >> q;
        int diffs = 0;
        for(int i = 0;i < n;++i)
            diffs += (s[0][i] != s[1][i]);
        vector<int>block(n + 10);
        vector<vector<int> >pos(q + 10);
        for(int i = 1;i <= q;++i)
        {
            for(auto temp : pos[i])
            {
                if(--block[temp] == 0)
                {
                    diffs += (s[0][temp] != s[1][temp]);
                }
            }
            int op;
            cin >> op;
            if(op == 1)
            {
                int x = 0;
                cin >> x ;
                x--;
                if(++block[x] == 1)
                {
                    diffs -= (s[0][x] != s[1][x]);
                }
                if(i + t <= q)
                {
                    pos[i + int(t)].push_back(x);
                }
            }else if(op == 2)
            {
                int pos_1,pos_2,index_1,index_2;
                cin >> pos_1 >> index_1 >> pos_2 >> index_2;
                pos_1--,pos_2--,index_1--,index_2--;
                if(s[0][index_1] == s[1][index_1])
                {
                    diffs ++;
                }
                if(s[0][index_2] == s[1][index_2])
                {
                    diffs ++;
                }
                swap(s[pos_1][index_1],s[pos_2][index_2]);
                if(s[0][index_1] == s[1][index_1])
                {
                    diffs --;
                }
                if(s[0][index_2] == s[1][index_2])
                {
                    diffs --;
                }
            }else if(op == 3)
            {
                if(diffs)
                {
                    cout << "NO" << '\n';
                }else 
                    cout << "YES" << '\n';
            }
        }
    }
}