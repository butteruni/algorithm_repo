#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
string s;
map<char,int>cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        vector<int>cnt(26);
        int n,m;
        string s;
        cin>>n>>m>>s;
        for(int i=0;i<n;i++)
            cnt[s[i]-'a']++;
        int c=0;
        n-=m;
        for(int i=0;i<26;i++)
            c+=cnt[i]/2;
        cout<<(c>=n/2? "YES":"NO")<<'\n';
    }
}