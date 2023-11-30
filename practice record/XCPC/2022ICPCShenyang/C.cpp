#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll d;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>d;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll cnt=0;
        ll l=a[i];
        ll r=a[i]+d;
        for(int j=2;j<=n;j++)
        {
            ll tmp1=a[j-1];
            ll tmp2=a[j];
            tmp1=max(l,tmp1);
            tmp2=max(l,tmp2);
            tmp1=min(r,tmp1);
            tmp2=min(r,tmp2);
            cnt+=abs(tmp1-tmp2);
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}