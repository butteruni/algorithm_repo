#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,int>mp;
void print(int x)
{
    if(x == 1)
    {
        cout << ">\n";
    }else if(x == 0)
    {
        cout << "=\n";
    }else 
    {
        cout << "<\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    mp['S'] = 1,mp['M'] = 2,mp['L'] = 3;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int sz_a = a.size();
        int sz_b = b.size();
        if(a.back() == b.back())
        {
            int ok;
            if((sz_a > sz_b && a.back() == 'L') || (sz_a < sz_b && a.back() == 'S'))
            {
                print(1);
            }else if(sz_a == sz_b)
            {
                print(0);
            }else 
            {
                print(-1);
            }
        }else 
        {
            int aa = mp[a.back()];
            int bb = mp[b.back()];
            if(aa > bb)
            {
                print(1);
            }else if(aa == bb)
            {
                print(0);
            }else 
            {
                print(-1);
            }
        }

    }
    
}