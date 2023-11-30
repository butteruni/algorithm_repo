#include <bits/stdc++.h>
using namespace std;
bool cmp(string x,string y)
{
    return x.size() < y.size();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<string>s;
    for(int i = 1;i <= n;++i)
    {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(),s.end(),cmp);
    bool ok = 1;
    for(int i = 0;i < n - 1;++i)
    {
        string u = s[i];
        string pa = s[i + 1];
        bool cur_ok = 0;
        int pre_sz = s[i].size();
        for(int j = 0;j < pa.size() - pre_sz + 1;++j)
        {
            string tmp = pa.substr(j,pre_sz);
            // cout << tmp << endl;
            if(tmp == u)
            {
                cur_ok = 1;
                break;
            }
        }
        if(!cur_ok)
        {
            ok = 0;
            break;
        }
    }
    if(!ok)
    {
        cout << "NO";
    }else 
    {
        cout << "YES\n";
        for(auto x:s)
        {
            cout << x << "\n";
        }
    }
}