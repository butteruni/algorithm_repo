#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
bool vis[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    vector<int>pos_2;
    vector<int>pos_1;
    for(int i = 1;i <= n;++i)
    {
        if(a[i] == 2)
        {
            pos_2.push_back(i);
        }else if(a[i] == 1)
            pos_1.push_back(i);
    }
    for(auto x: pos_2)
    {
        if(!vis[x])
        {
            ans++;
        }
        vis[x] = 1;
        int l = x,r = x;
        while(a[l] != 0 && l >= 1)
        {
            l--;
            vis[l] = 1;
        }
        while(a[r] != 0 && r <= n)
        {
            r++;
            vis[r] = 1;
        }
    }
    for(auto x : pos_1)
    {
        if(!vis[x])
            ans++;
        else 
        {
            continue;
        }
        int l = x;
        bool used = 0;
        if()
    }
}