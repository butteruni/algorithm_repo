#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    map<int,int>mp;
    vector<int>ans;
    for(int i = 0;i < n;++i)
    {
        int x;
        cin >> x;
        if(!mp.count(x))
        {
            mp[x] = 1;
            ans.push_back(i + 1);
        }
    }
    if(ans.size() < k)
    {
        cout << "NO" << '\n';
    }else 
    {
        cout << "YES\n";
        for(int i = 0;i < k;++i)
        {
            cout << ans[i] << " ";
        }
    }
}