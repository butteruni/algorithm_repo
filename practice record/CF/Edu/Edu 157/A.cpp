#include <bits/stdc++.h>
using namespace std;
vector<int>a(9);
int main()
{
    int sz = a.size();
    for(int i = 1;i <= sz;++i)
        a[i] = i;
    cout << a[sz] << '\n';
}