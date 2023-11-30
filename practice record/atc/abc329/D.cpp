#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 200100;
int a[N];
int c[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int mx = 0;
    int id = 0;
    for(int i = 1;i <= m;++i)
    {
        cin >> a[i];
        c[a[i]]++;
        if(c[a[i]] > mx)
        {
            mx = c[a[i]];
            id = a[i];
        }else if(c[a[i]] == mx && a[i] < id)
        {
            id = a[i];
        }
        cout << id << '\n';
    }
    
    
}