#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 0;
    for(int i = 0 ;i < n - 1;++i)
    {
        if(s[i] == 'a' && s[i + 1] == 'b')
            ok = 1;
        else if(s[i] == 'b' && s[i + 1] == 'a')
            ok = 1;
    }
    if(ok)
    {
        cout << "Yes\n";
    }else
    {
        cout << "No\n";
    }
}