#include <bits/stdc++.h>
using namespace std;
int string_to_int(string s,int k)
{
    int ans = 0;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
            ans += (s[i] - '0');
        else
            ans += s[i] - 'A' + 10; 
        ans *= k;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string a,b,S;
        cin >> a >> b >> S;
        int st = 2;
        for(auto x:a)
        {
            if(x >= '0' && x <= '9')
            {
                st = max(st, x - '0' + 1);
            }else 
            {
                st = max(st, x - 'A' + 10 + 1);
            }
        }
        for(auto x:b)
        {
            if(x >= '0' && x <= '9')
            {
                st = max(st, x - '0' + 1);
            }else 
            {
                st = max(st, x - 'A' + 10 + 1);
            }
        }
        for(auto x:S)
        {
            if(x >= '0' && x <= '9')
            {
                st = max(st, x - '0' + 1);
            }else 
            {
                st = max(st, x - 'A' + 10 + 1);
            }
        }
        bool ok = 0;
        for(int k = st;k <= 16;++k)
        {
            if(string_to_int(S,k) == string_to_int(a,k) + string_to_int(b,k))
            {
                ok = 1;
                cout << k << '\n';
                break;
            }
        }
        assert(ok == 1);
    }
}