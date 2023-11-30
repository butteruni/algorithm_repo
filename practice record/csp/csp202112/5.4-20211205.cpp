#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int e[N << 1],ne[N << 1],h[N],idx;
int max_son[N],root,siz[N];
int sum,MAX_TREE,n,k1,k2;
int ch[N * 20][2],sz[N * 20],top,rt[N];//可持久化线段树相关操作
bool st[N];
ll ans;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
void dfs(int x,int fa)//遍历图更新子树和子树根节点信息
{
    siz[x] = 1;
    max_son[x] = 0;
    for(int i = h[x];i != -1;i = ne[i])
    {
        int j = e[i];
        if(j == fa || st[j])
            continue;
        dfs(j, x);
        siz[x] += siz[j];
        max_son[x] = max(max_son[x],siz[j]);
    }
    max_son[x] = max(max_son[x],sum - siz[x]);
    if(max_son[x] < MAX_TREE)
    {
        MAX_TREE = max_son[x];
        root = x;
    }
}
int newnode(int x)
{
    sz[++top] = sz[x];
    ch[top][0] = ch[x][0];
    ch[top][1] = ch[x][1];
    return top;
}
void insert(int& rx,int l,int r,int val)//插入val，rx变为插入后线段树根节点
{
    rx = newnode(rx);
    sz[rx]++;
    int x = rx;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(val <= mid)
        {
            ch[x][0] = newnode(ch[x][0]);
            x = ch[x][0],sz[x]++,r = mid;
        }else 
        {
            ch[x][1] = newnode(ch[x][1]);
            x = ch[x][1],sz[x]++,l = mid + 1;
        }
    }
}
int get(int rx,int l,int r,int limit)//得到以rx为根节点的所有可行路径
{
    int cnt = 0;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(limit <= mid)//不满足限制则查找左子树，满足则计算贡献并查找右子树
            rx = ch[rx][0], r = mid;
        else 
            cnt += sz[ch[rx][0]],rx = ch[rx][1],l = mid + 1;
    }
    cnt += sz[rx];
    return cnt;
}
void get_(int x,int fa, vector<int>& nodes,pair<int,int>* value, int mn,int mx)
{
    nodes.push_back(x);
    value[x].first = mn,value[x].second = mx;
    for(int i = h[x]; i != -1;i = ne[i])
    {
        int j = e[i];
        if(!st[j] && j != fa)
        {
            get_(j,x,nodes,value,min(mn,j),max(mx,j));
        }
    }
}
ll solve(int x,int mn,int mx)
{
    // cout << x << endl;
    // cout << "---" << endl;
    vector<int> nodes;
    static int w[N]; //使用static修饰变量避免爆空间
    static pair<int,int> value[N];
    get_(x,0,nodes,value,min(mn,x),max(mx,x)); //更新以x为根节点的树上信息
    for(int i = 0;i < nodes.size();i++)
    {
        w[i] = nodes[i];
    }
    sort(w,w + nodes.size());
    ll cnt = 0;
    top = 0;
    rt[0] = 0;
    for(int i = 0;i < nodes.size();++i)
    {
        auto p = value[w[i]];
        if(i)
            rt[i] = rt[i - 1];
        if(w[i] - k1 <= p.first)//若满足一个条件则插入
            insert(rt[i],1,n,p.second);
        if(w[i] + k2 >= p.second)
        {
            int nv = p.first + k1;
            int l = -1, r = nodes.size() - 1;
            while(l < r)
            {
                int mid = l + r + 1>> 1;
                if(w[mid] > nv)
                    r = mid - 1;
                else 
                    l = mid;
            }
            int pos = min(l,i);
            if(pos >= 0)//如果存在满足条件的版本则查找
                cnt += get(rt[pos],1,n,w[i] + k2);
        }
    }
    return cnt;
}
void Divide(int rx)
{
    ans += solve(rx,INF,0); //加上以rx为根节点所有可能路径
    st[rx] = 1;
    for(int i = h[rx];i != -1;i = ne[i])
    {
        int j = e[i];
        if(st[j])
            continue;
        ans -= solve(j,rx,rx); //减去j到rx之间所有可能路径
        sum = siz[j];
        MAX_TREE = INF;
        dfs(j,0);
        Divide(root);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof(h));
    cin >> n >> k1 >> k2;
    for(int i = 1;i < n;++i) //链式前向星建无向图
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    MAX_TREE = INF;
    sum = n;
    dfs(1,0);
    Divide(root);
    cout << ans << endl;
}