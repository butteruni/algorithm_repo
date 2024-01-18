#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    string a,b;
    cin >> a >> b; 
    // 两个都能删则删，然后比较剩下的？
    // AB -> ABABAB -> AB
    // BA -> ABABBA -> AB
    // BC -> ...... -> BC
    // CB -> BCBCCB -> BC
    // AC -> AC
    // CA -> CA
    // B 都能消掉 ? 
    for(int i = 0;i < a.size();++i)
    {
        if(i > 0)
        {
            string cur = a.substr(i - 1,2);
            if(cur == "AA" || cur == "BB" || cur == "CC")
            {
                a.erase(i - 1,2);
                i -= 2;
            }
            if(cur == "BA")
            {
                swap(a[i],a[i - 1]);
            }
        }
        if(i > 1)
        {
            string cur = a.substr(i-2,3);
            if(cur == "ABA" || cur =="BAA" || cur =="AAB" || cur =="CCB" || cur =="CBC" || cur =="BCC") // 将其中两个像一样变化
            {
                a.erase(i-2,3);
                a.insert(i-2,"B");
                i -= 3;
            }
            if(cur == "ABB" || cur =="BBA" || cur =="BAB")
            {
                a.erase(i-2,3);
                a.insert(i-2,"A");
                i -= 3;
            }
            if(cur =="BCB" || cur =="CBB" || cur =="BBC")
            {
                a.erase(i-2,3);
                a.insert(i-2,"C");
                i -= 3;
            }
        }
    }
    for(int i = 0;i < b.size();++i)
    {
        if(i > 0)
        {
            string cur = b.substr(i - 1,2);
            if(cur == "AA" || cur == "BB" || cur == "CC")
            {
                b.erase(i - 1,2);
                i -= 2;
            }
            if(cur == "BA" || cur == "CB")
            {
                swap(b[i],b[i - 1]);
            }
        }
        if(i > 1)
        {
            string cur = b.substr(i-2,3);
            if(cur == "ABA" || cur =="BAA" || cur =="AAB" || cur =="CCB" || cur =="CBC" || cur =="BCC") // 将其中两个像一样变化
            {
                b.erase(i-2,3);
                b.insert(i-2,"B");
                i -= 3;
            }
            if(cur == "ABB" || cur =="BBA" || cur =="BAB")
            {
                b.erase(i-2,3);
                b.insert(i-2,"A");
                i -= 3;
            }
            if(cur =="BCB" || cur =="CBB" || cur =="BBC")
            {
                b.erase(i-2,3);
                b.insert(i-2,"C");
                i -= 3;
            }
        }
    }
    int cnt_a = 0,cnt_b = 0;
    // cout << a << '\n' << b << "\n";
    for(int i = 0;i < a.size();++i)
    {
        if(a[i] == 'B')
        {
            a.erase(i,1);
            i--;
            cnt_a++;
        }
    }
    for(int i = 0;i < b.size();++i)
    {
        if(b[i] == 'B')
        {
            b.erase(i,1);
            i--;
            cnt_b++;
        }
    }
    if(a == b && abs(cnt_a - cnt_b) % 2 == 0)
    {
        cout << "YES\n";
    }else 
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}