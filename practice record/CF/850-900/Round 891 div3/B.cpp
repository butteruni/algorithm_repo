#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        s = "0" + s;
        int n = s.size();
        int pre_pos = 0;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '4')
            {
                int j = i;
                while(s[j] == '4' && j < n)
                {
                    j++;
                }
                if(j == n)
                    break;
                if(s[j] < '5')
                {
                    continue;
                    i = j;
                }else 
                {

                    for(int k = i;k < n;++k)
                    {   
                        s[k] = '0';
                    }
                    s[i - 1]++;
                    break;
                }
            }else if(s[i] >= '5' && s[i] <= '9') 
            {
                s[i - 1]++;
                for(int j = i;j < n;++j)
                {
                    s[j] = '0';
                }
                break;
            }else 
            {
                continue;
            }
        }
        if(s[0] == '0')
        {
            s = s.substr(1,n - 1);
        }
        cout << s << '\n';
    }
}