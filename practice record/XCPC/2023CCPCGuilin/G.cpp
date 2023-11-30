#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        string s;   
        cin >> s;
        string ans = s;
        int sz = s.size();
        s = " " + s;
        vector<int>vis(sz + 2);
        int cnt = 0;
        for(int i = 1;i <= sz;++i)
        {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')')
            {
                if(cnt) 
                    cnt--;
            }
        }
        if(cnt) 
            cout << "impossible\n";
        else 
            cout << ans <<"\n";

   }
}