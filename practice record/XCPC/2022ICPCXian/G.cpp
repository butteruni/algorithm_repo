#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int>mp;
bool cmp(string a,string b)
{
    return a.size() < b.size();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int n;
    cin >> n;
    vector<string>s(n);
    for(int i = 0;i < n;++i)
        cin >> s[i];
    sort(s.begin(),s.end(),cmp);
    int ans = 0;
    for(int i = 0;i < n;++i)
    {
        if(s[i].size() == 1)
        {
            mp[s[i]] = 1;
            ans = max(ans,(int)s[i].size());
        }else 
        {
            int sz = s[i].size();
            string a = s[i].substr(0,sz - 1);
            string b = s[i].substr(1,sz - 1);
            if(mp.count(a) && mp.count(b))
            {
                ans = max(ans,(int)s[i].size());
                mp[s[i]] = 1;
            }
        }
    }
    cout << ans << '\n';
    
    
}