#include <bits/stdc++.h>
using namespace std;
bool changed = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        changed = 0;
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0;i < len;++i)
        {
            if(s[i] == '?')
                continue;
            changed = 1;
            int l = i - 1,r = i + 1;
            while(l >= 0)
            {
                if(s[l] != '?')
                    break;
                else 
                    s[l] = s[i];
                l --;
            }   
            while(r <= len)
            {
                if(s[r] != '?')
                    break;
                else 
                    s[r] = s[i];
                r++;
            }
        }
        if(!changed)
        {
            for(int i = 0;i < len;++i)
                s[i] = '1';
        }
        cout << s << '\n';
    }
}