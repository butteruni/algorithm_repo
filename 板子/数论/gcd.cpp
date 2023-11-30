#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}
ll x,y;
int main()
{
    ios::sync_with_stdio(false);
    cin>>x>>y;
    cout<<gcd(x,y);
    return 0;
}
