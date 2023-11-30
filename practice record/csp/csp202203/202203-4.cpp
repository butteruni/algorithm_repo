#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N = 1e5 +  10;
int n,m;
struct LINE
{
    ll val,en;
    LINE(ll val,ll en) : val(val),en(en){}
    bool operator < (const LINE &x)const 
    {
        if(val == x.val)
            return en < x.en;
        else 
            return val > x.val;
    }

};
struct link
{
    int st,en,val;
};
set<LINE>correspondence_object[N];
map<PII,ll>flow;
vector<link>link_history[N];
int pair_cnt,isolate_cnt;
int max_correspondence_object(int node)
{
    return correspondence_object[node].begin()->en;
}
bool is_isolate(int node)
{
    return correspondence_object[node].begin()->val == 0 ;
}
bool is_max_correspondence_pair(int a,int b)
{
    if(is_isolate(a) || is_isolate(b))
        return false;
    return max_correspondence_object(a) == b && a == max_correspondence_object(b);
}
void add(int x,int y,int val)
{
    ll pre_flow = flow[{x,y}]; 
    flow[{x,y}] = max(flow[{x,y}] + val,(ll)0);
    flow[{y,x}] = max(flow[{y,x}] + val,(ll)0);
    pair_cnt -= is_max_correspondence_pair(x,correspondence_object[x].begin()->en);
    pair_cnt -= is_max_correspondence_pair(y,correspondence_object[y].begin()->en);
    isolate_cnt -= is_isolate(x);
    isolate_cnt -= is_isolate(y);
    if(is_max_correspondence_pair(x,y))
    {
        pair_cnt++;
        // cout << x << "|" << y << endl;
    }
    correspondence_object[x].erase({pre_flow,y});
    correspondence_object[y].erase({pre_flow,x});
    correspondence_object[x].emplace(flow[{x,y}],y);
    correspondence_object[y].emplace(flow[{x,y}],x);
    pair_cnt += is_max_correspondence_pair(x,correspondence_object[x].begin()->en);
    isolate_cnt += is_isolate(x);
    pair_cnt += is_max_correspondence_pair(y,correspondence_object[y].begin()->en);
    isolate_cnt += is_isolate(y);
    if(is_max_correspondence_pair(x,y))
    {
        pair_cnt--;
    }
    // cout << correspondence_object[2].begin()->en <<"|"<< '\n';
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        correspondence_object[i].emplace((ll)0,0);
    }
    isolate_cnt = n;
    for(int i = 1;i <= m;++i)
    {
        int k;
        cin >> k;
        for(auto temp : link_history[i])
        {
            add(temp.st,temp.en,-temp.val);
        }
        for(int j = 1;j <= k;++j)
        {
            int u,v,x,y;
            cin >> u >> v >> x >> y;
            if(i + y <= m)
            {
                link temp = {u,v,x};
                link_history[i + y].emplace_back(temp);
            }
			add(u,v,x);
        }
        int l;
        cin >> l;
        for(int j = 1;j <= l;++j)
        {
            int node;
            cin >> node;
            if(is_isolate(node))
            {
                cout << '0' << '\n';
            }else 
            {
                cout << correspondence_object[node].begin()->en << '\n';
            }
        }
        int p,q;
        cin >> p >> q;
        if(p)
        {
            cout << isolate_cnt << '\n';
        }
        if(q)
        {
            cout << pair_cnt << '\n';
        }
        // for(int j = 1;j <= n;++j)
        // {
        //     cout << j << "-" << correspondence_object[j].begin()->en << "\n";
        // }
    }
}