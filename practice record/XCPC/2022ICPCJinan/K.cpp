#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        set<int>vis;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int val;
            cin>>val;
            if(!vis.count(val+1))
            {
                ans++;
            }
            vis.insert(val);
        }
        cout<<ans<<"\n";
    }
    return 0;
}