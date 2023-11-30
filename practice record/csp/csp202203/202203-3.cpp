#include <bits/stdc++.h>
using namespace std;
const int N = 1e5  + 10;
typedef pair<int,int> PII;
unordered_map<int,int> node_app;//节点上的应用数
unordered_map<int,vector<int> >app_node;//每个应用有哪些节点
vector<int> area[N];//区域中所有节点
int address[N]; //节点所在区域
int n,m,g;
int l[N];
bool count_node_familiar(int node_id,int area_id)
{
    if(area_id == 0)
    {
        return true;
    }
    bool success = 0;
    for(auto temp : area[area_id])
    {
        if(node_id == temp)
        {
            success = 1;
            break;
        }
    }
    return success;
}
bool  count_task_familiar(int task_id,int app_id)
{
    if(app_id == 0)
    {
        return true;
    }
    bool success = 0;
    for(auto temp : app_node[app_id])
    {
        if(address[task_id] == address[temp])
        {
            success = 1;
            break;
        }
    }
    return success;   
}
bool count_task_anti_familiar(int task_id,int app_id)
{
    if(app_id == 0)
    {
        return true;
    }
    bool success = 1;
    for(auto temp : app_node[app_id])
    {
        if(task_id == temp)
        {
            success = 0;
            break;
        }
    }
    return success;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        int l;
        cin >> l;
        area[l].push_back(i);
        address[i] = l;
    }
    cin >> g;
    while(g--)
    {
        int f,a,na,pa,paa,paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        for(int i = 1;i <= f;++i)
        {
            vector<int> complete,half_complete;
            for(int j = 1;j <= n;++j)
            {
                if(count_node_familiar(j,na) && count_task_familiar(j,pa)  && count_task_anti_familiar(j,paa))
                {
                    complete.push_back(j);
                }
                if(!paar && count_node_familiar(j,na) && count_task_familiar(j,pa))
                {
                    half_complete.push_back(j);
                }
            }
            if(complete.size() == 0 && !paar)
            {
                complete = half_complete;
            }
            if(complete.size() == 0)
            {
                cout << 0 << ' ';
            }else 
            {
                vector<PII> nodes;
                for(auto temp: complete)
                {
                    nodes.push_back({node_app[temp],temp});
                } 
                sort(nodes.begin(),nodes.end());
                cout << nodes[0].second << " ";
                node_app[nodes[0].second]++;
                app_node[a].push_back(nodes[0].second);
            }
        }
        cout << '\n';
    }
}