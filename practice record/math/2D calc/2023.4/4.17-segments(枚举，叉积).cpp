//POJ-3304
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
const db eps = 1e-8;
    
int n;
struct po
{
    db x,y;
}p[N];

db make_cross(db x1,db y1,db x2, db y2)
{
    return x1 * y2 - x2 * y1;
}
bool if_equal(int idx1,int idx2)
{
    if(fabs(p[idx1].x - p[idx2].x) < eps && fabs(p[idx1].y - p[idx2].y) < eps)
        return true;
    return false;
}
bool check(int idx1,int idx2)
{
    db a = p[idx2].y - p[idx1].y;
    db b = p[idx1].x - p[idx2].x;
    db c = p[idx2].x * p[idx1].y - p[idx2].y * p[idx1].x;
    for(int i = 1;i <= n * 2;i += 2)
    {
        //叉积判断相交
        db s1 = a * p[i].x + b * p[i].y + c;
        db s2 = a * p[i + 1].x + b * p[i + 1].y + c;
        if(fabs(s1) > eps && fabs(s2) > eps && s1 * s2 > 0)
            return false;
    }
    return true;
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= 2 * n;i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    if(n == 1)
    {
        cout << "Yes!" << '\n';
        return;
    }   
    bool success = 0;
    for(int i = 1;i <= n * 2;i++)
    {
        for (int j =  i + 1; j <= n * 2; j++)
        {
            if(if_equal(i, j))
                continue;
            if(check(i, j))
            {
                success = 1;
                // cout << i << "--" << j << '\n';
                break;
            }
        }
        if(success)
            break;
    }
    if(success)
        cout << "Yes!" << '\n';
    else 
        cout << "No!" << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}