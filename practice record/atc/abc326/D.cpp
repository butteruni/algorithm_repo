#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    string r,c;
    cin >> n >> r >> c;
    if(r[0] != c[0])
    {
        cout << "No\n";
    }else 
    {
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= n;++j)
            {
                if(j == 1)
                {
                    cout << r[i - 1] ;
                }else if(i == j)
                {
                    cout << c[i - 1] ;
                }else 
                    cout << '.';
            }
            cout << '\n';
        }
    }
}