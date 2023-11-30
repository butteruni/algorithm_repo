#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m;
    cin >> m;
    for(int i = 1;i <= m;++i)
    {
        int op,x;
        cin >> op >> x;
        if(op == 2)
        {
            for(int j = 2;j * j <= x;++j)
            {
                while(x % j == 0)
                {
                    mp[j]++;
                    x /= j;
                }
            }
            if(x != 1)
                mp[x] ++;
        }else 
        {
            for(int j = 2;j * j <= x;++j)
            {
                while(x % j == 0)
                {
                    mp[j]--;
                    x /= j;
                }
            }
            if(x != 1)
                mp[x] --;
        }
    }
    cin >> m;
    for(int i = 1;i <= m;++i)
    {
        int op,x;
        cin >> op >> x;
        if(op == 2)
        {
            for(int j = 2;j * j <= x;++j)
            {
                while(x % j == 0)
                {
                    mp[j]--;
                    x /= j;
                }
            }
            if(x != 1)
                mp[x] --;
        }else 
        {
            for(int j = 2;j * j <= x;++j)
            {
                while(x % j == 0)
                {
                    mp[j]++;
                    x /= j;
                }
            }
            if(x != 1)
                mp[x] ++;
        }
    }
    bool ok = 1;
    for(auto [x,val]:mp)
    {
        if(val != 0)
            ok = 0;
    }
    if(!ok)
    {
        cout << "NO\n";
    }else 
    {
        cout << "YES\n";
    }
}