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
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt_a = 0;
        ll sum = 0;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == 'A')
                cnt_a++;
            else 
            {
                sum += cnt_a;
                cnt_a = min(cnt_a,(ll)1);
            }
        }
        cout << sum << '\n';
    }
}