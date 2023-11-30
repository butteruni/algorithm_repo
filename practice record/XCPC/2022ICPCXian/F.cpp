#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,c1,c2;
    cin >> n >> c1 >> c2;
    vector<string>s(n);
    for(int i = 0;i < n;++i)
    {
        cin >> s[i];
    }
    if(c1 * 2 <= c2)
    {
        cout << 3ll * n * c1 << '\n';
    }else 
    {
        int cnt_1 = 0,cnt_2 = 0;
        for(int i = 0;i < n;++i)
        {
            map<char,int>mp;
            for(int j = 0;j < 3;++j)
            {
                mp[s[i][j]]++;
            }
            for(auto &[x,val]:mp)
            {
                while(val >= 2)
                {
                    val -= 2;
                    cnt_2++;
                }
                cnt_1 += val;
            }
        }
        cout << cnt_1 * min(c1,c2) + cnt_2 * c2 << '\n';
    }
}