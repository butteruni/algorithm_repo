#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string a,string b)
{
    bool ok = 0;
    if(a.size() < b.size())
    {
        return 0;
    }
    for(int i = 0;i < a.size() && !ok;++i)
    {
        int j = 0;
        while(a[i + j] == b[j] && j < b.size() && i + j < a.size())
        {
            j++;
        }   
        if(j == b.size())
        {
            ok = 1;
        }
    }
    return ok;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        string a,b;
        cin >> n >> m >> a >> b;
        int ans = 0;
        while(!check(a,b) && (a.size() < 3 * b.size() ||  ans <= 4))
        {
            ans++;
            a = a + a;
        }
        if(!check(a,b))
        {
            cout << -1 << '\n';
        }else{
            cout << ans << '\n';
        }
    }
}