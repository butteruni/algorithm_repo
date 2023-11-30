#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N],n,cnt_1,cnt_2;
ll pre[N];
int t;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        cnt_1 = 0,cnt_2 = 0;
        priority_queue<int, vector<int>, greater<int>>ne;
        priority_queue<int, vector<int>, greater<int>>po;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '(')
            {
                a[i + 1] = 1;
                cnt_1++;
                po.push(i + 1);
            }
            else 
            {
                a[i + 1] = -1;
                cnt_2 ++;
                ne.push(i + 1);
            }
        }
        if(cnt_1 != cnt_2)
        {
            cout << -1 << endl;
        }else 
        {
            int sum =0;
            ll move = 0;
            for(int i = 1;i <= n;++i)
            {
                if(a[i] < 0)
                {
                    ne.pop();
                }
                else 
                {
                    po.pop();
                }
                sum += a[i];
                if(sum < 0)
                {
                    int temp = po.top();
                    move += temp - i;
                    sum += 2;
                    ne.push(temp);
                    swap(a[i],a[temp]);
                    po.pop();
                }
            }
            cout << move << endl;
        }
    }
}