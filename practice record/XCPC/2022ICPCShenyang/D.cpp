#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    bool ok = 0;
    for(int i = 0;i < 5;++i)
    {
        mp[s[i]]++;
        if(mp[s[i]] >= 3)
        {
            ok = 1;
            if(s[i] == 'T')
            {
                cout << "T1\n";
            }else 
            {
                cout << "DRX\n";
            }
        }
    }
    assert(ok == 1);
}