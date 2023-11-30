#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e3+10;
int f[N];
int sz[N];
int find(int x)
{
    return x==f[x]?x:f[x]=find(f[x]);
}
string tolower(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
    }
    return s;
}

map<string,int>s2i;
map<string,int>c2i;
int cnt;
int cntc;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string city[1010];

    vector<int>ls[1010];
    vector<int>cls[1010];
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        sz[i]=1;
        string s;
        cin>>s;
        int pre=0,idx;
        map<string,bool>vis;
        for(idx=0;idx<s.length();idx++)
        {
            if(s[idx]=='_')
            {
                string t=tolower(s.substr(pre,idx-pre));
                if(!vis[t])
                {
                    vis[t]=true;
                    if(!s2i[t])s2i[t]=++cnt;
                    ls[s2i[t]].push_back(i);
                }
                pre=idx+1;
            }
        }
        string t=tolower(s.substr(pre,idx-pre));
        if(!vis[t])
        {
            if(!s2i[t])s2i[t]=++cnt;
            ls[s2i[t]].push_back(i);
        }
        
        cin>>city[i];
        city[i]=city[i];
        if(!c2i[city[i]])c2i[city[i]]=++cntc;
        cls[c2i[city[i]]].push_back(i);
    }
    for(int i=1;i<=cntc;i++)
    {
        for(int j=1;j<cls[i].size();j++)
        {
            int u=cls[i][j-1];
            int v=cls[i][j];
            int fu=find(u);
            int fv=find(v);
            if(fu==fv)continue;
            f[fv]=fu;
            sz[fu]+=sz[fv];
        }
    }
    while(m--)
    {
        string t;
        cin>>t;
        t=tolower(t);
        int id=s2i[t];
        for(int i=1;i<ls[id].size();i++)
        {
            int u=ls[id][i-1];
            int v=ls[id][i];
            int fu=find(u);
            int fv=find(v);
            if(fu==fv)continue;
            f[fv]=fu;
            sz[fu]+=sz[fv];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<sz[find(i)]-1<<"\n";
    }
    

    return 0;
}
