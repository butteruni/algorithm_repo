#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1000;
struct node
{
    int x,y,val,attack;
};
struct pao
{
    int x,y,attack;
};
pao ls[N];
ll calc_dis(pao a,node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
void solve()
{
    int n,a,b,p;
    cin >> n >> a >> b >> p;
    for(int i = 1;i <= a;++i)
    {
        cin >> ls[i].x >> ls[i].y >> ls[i].attack;
    }
    map<int,node>mp;
    for(int i = 1;i <= b;++i)
    {
        node cur;
        cin >> cur.x >> cur.y >> cur.attack >> cur.val;
        mp[i] = cur;
    }
    int end = 0;
    
    for(int i = 1;i <= n && (p > 0) && mp.size() ;++i)
    {
        end++;
        for(int i = 1;i <= a;++i)
        {
            ll dis = 1e18;
            ll idx = 0;
            for(auto [id,enemy]:mp)
            {
                if(dis > calc_dis(ls[i],enemy))
                {
                    dis = calc_dis(ls[i],enemy);
                    idx = id;
                }
            }
            mp[idx].val -= ls[i].attack;
            // cout << idx << " ";
            if(mp[idx].val <= 0)
                mp.erase(idx);
            if(mp.size() == 0)
            {
                // end = i;
                break;
            }
        }
        for(auto [id,enemy]:mp)
        {
            bool moved = 0;
            if(abs(mp[id].x) + abs(mp[id].y) <= 1)
            {
                p -= mp[id].attack;
                continue;
            }
            if(mp[id].y == 0)
            {
                if(mp[id].x < -1)
                    mp[id].x++;
                else if(mp[id].x > 1)
                    mp[id].x--;
            }else if(mp[id].x != 0)
            {
                if(mp[id].x < 0)
                    mp[id].x++;
                else if(mp[id].x > 0)
                    mp[id].x--;
            }else 
            {
                if(mp[id].y < 0)
                    mp[id].y++;
                else if(mp[id].y > 0)
                    mp[id].y--;
            }
        }
    }
    if(p > 0 && mp.size())
    {
        cout << "Draw\n";
        cout << p << " " << mp.size() << '\n';
    }else if(p > 0)
    {
        cout << "Win\n";
        cout << end << " " << p << "\n";
    }else 
    {
        cout << "Lose\n";
        cout << end << " " << mp.size() << "\n";
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}