#include <bits/stdc++.h>
using namespace std;
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
        vector<int>a(n);
        for(int i = 0;i < n;++i)
            cin >> a[i];
        vector<int>pos[100 + 1];
        for(int i = 0;i < n;++i)
        {
            pos[a[i]].push_back(i);
        }
        int k = 2;
        vector<int>b(n,1);
        for(int x = 1;x <= 100;++x)
        {
            if((int)pos[x].size() >= 2)
            {
                b[pos[x][0]] = k;
                k++;
                if(k > 3)
                    break;
            }
        }
        if(k <= 3)
        {
            cout << -1 << '\n';
        }else 
        {
            for(auto x:b)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        
    }
}