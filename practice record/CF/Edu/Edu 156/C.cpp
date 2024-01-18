#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool cmp(int a,int b)
{
    return s[a] > s[b];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ll n;
        cin >> n;
        ll sz = s.size();
        n--;
        ll l = 1,r = sz;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            // cout << mid << endl;
            ll sum = (sz - mid + 1 + sz) * mid / 2;
            if(sum < n)
            {
                l = mid + 1;
            }else if(sum >= n)
            {
                r = mid;
            }
        } 
        l --;
        ll res = n - (sz - l + 1 + sz) * l / 2;
        if(res == sz - l)
        {
            res = 0;
            l++;
        }
        string tmp;
        for(auto x:s)
        {
            while(l > 0 && !tmp.empty() && x < tmp.back())
            {
                tmp.pop_back();
                l--;
            }
            tmp += x;
        }
        cout << tmp[res];
    }
}