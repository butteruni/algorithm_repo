#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> n >> s;
        int pos = 0;
        while(pos < n)
        {
            char pre = s[pos];
            pos++;
            while(s[pos] != pre && pos < n)
            {
                pos++;
            }
            pos++;
            cout << pre;
        }
        cout << '\n';
    }
}