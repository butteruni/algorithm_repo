#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,q;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> q;
    cin >> s;
    for(int i = 1;i <= m;++i)
    {
        int l,r;
        cin >> l >> r;
        swap(s[l - 1],s[r - 1]);
    }
    cout << s << endl;
    // for(int i = 1;i <= q;++i)
    // {
    //     int x;
    //     cin >> x;   
    //     x -= 1;
    //     if(s[x] == '1')
    //         s[x] = '0';
    //     else 
    //         s[x] = '1';
    // }
}