#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    for(int i = 1;i < n;++i)
    {
        if(s[i] == s[i + 1])
            cnt[i]++;
    }
    for(int i = 1;i <= n;++i)
        cnt[i] += cnt[i - 1];
    for(int i = 1;i <= q;++i)
    {
        int l,r;
        cin >> l >> r;
        int ans = cnt[r - 1] - cnt[l - 1];
        if(cnt[r] != cnt[r - 1])
            ans--;
        cout << ans << '\n';
    }
}