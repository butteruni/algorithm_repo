#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int id[N];
bool cmp(int idx1,int idx2)
{
    return a[idx1] < a[idx2]; 
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i]; 
        id[i] = i;
    }  
    int cnt = 0;
    for(int i = 1;i <= n + 1;++i)
        if(a[i] == 0 && a[i - 1] != 0)
            cnt++;
    int x = 0;
    int temp = cnt;
    sort(id + 1,id + 1 + n,cmp);
    for(int i = 1;i <= n;++i)
    {
        if(a[id[i]])
        {
            int cur = id[i];
            if(a[cur] && cur != 1 && a[cur - 1] && cur != n && a[cur + 1])
                temp++;
            if(a[cur] && (cur == 1 || !a[cur - 1]) && (cur == n || !a[cur + 1]))
                temp--;
            if(i == n || a[id[i]] != a[id[i + 1]])
            {
                if(temp > cnt)
                    cnt = temp;
            }
            a[cur] = 0;
        }
    }
    cout << cnt << '\n';
}